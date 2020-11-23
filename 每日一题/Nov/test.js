// ==UserScript==
// @name         【万能】[超星学习通]网课及考试助手、[知到智慧树]网课及考试助手、[雨课堂]考试助手、[青版|蓝版]职教云icve|智慧职教MOOC答题考试助手、[超星]考试专版答题助手、[学堂云4.0]答题助手
// @namespace    冷月长空
// @version      1.8.0
// @description  超星挂机刷视频，刷讨论数，章节测验自动作答，超星考试自动作答，智慧树挂机刷视频，智慧树作业以及考试自动做答，支持[雨课堂][长江雨课堂]试卷类型的题目以及学校定制雨课堂章节测验的题目作答，支持蓝版本的智慧职教MOOC学院作业的答题，宜宾学院网址自动答题
// @author       冷月长空
// @match        *://*.chaoxing.com/*
// @match        *://*.edu.cn/*
// @match        *://*.hnsyu.net/*
// @match        *://*.zhihuishu.com/*
// @match        *://*.xuetangx.com/*
// @match        *://*.yuketang.cn/*
// @match        *://*.icve.com.cn/*
// @run-at       document-end
// @connect      user.lyck6.cn
// @grant        unsafeWindow
// @grant        GM_xmlhttpRequest
// @grant        GM_setClipboard
// @grant        GM_getValue
// @grant        GM_setValue
// @compatible   chrome
// @contributionURL   http://lyck6.cn/pay
// @@supportURL  https://greasyfork.org/zh-CN/scripts/409668-%E4%B8%87%E8%83%BD-%E8%B6%85%E6%98%9F-%E6%99%BA%E6%85%A7%E6%A0%91-%E9%9B%A8%E8%AF%BE%E5%A0%82-%E7%BD%91%E8%AF%BE%E5%8F%8A%E8%80%83%E8%AF%95%E5%8A%A9%E6%89%8B/feedback
// @require      https://unpkg.com/vue/dist/vue.js
// @require      https://cdn.bootcdn.net/ajax/libs/jquery/2.0.0/jquery.js
// @require      https://unpkg.com/element-ui/lib/index.js
// @require      https://cdn.bootcdn.net/ajax/libs/jsencrypt/2.1.0/jsencrypt.js
// @require      http://cdn.bootcss.com/blueimp-md5/1.1.0/js/md5.js
// @require      https://greasyfork.org/scripts/416237-jquery-and-vue/code/jQuery_and_Vue.js
// ==/UserScript==

var setting = {
    // 5E3 == 5000，科学记数法，表示毫秒数
    time: 5E3 // 默认响应速度为6秒，不建议小于5秒|后台有检测机制，请求频率过快会封ip
    ,review: 0 // 复习模式，完整挂机视频(音频)时长，支持挂机任务点已完成的视频和音频和章节测验作业等，默认关闭
    ,queue: 1 // 队列模式，开启后任务点逐一完成，关闭则单页面所有任务点同时进行，默认开启
    ,option: 1 //token用户是否使用token答题，1为开启，0为关闭，默认开始，可手动关闭
    ,token: '' //可在此设置token或者脚本搜索框内设置token后点击确定-->token就是你的手机号

    //超星用户自动刷讨论，下面内容可以自定义
    ,switch: 0 //是否刷讨论数量，1为开启，0为关闭，默认关闭
    ,topic: ['讲的不错','我还想听','这个老师真好','这个课让我受益匪浅','在大学我一定要好好学习','努力学习ing','原来超星的选修课都这么有意思可以哦','第一次听选修课这么爽']

    //雨课堂功能配置区域（不使用可不配置）-->本区域登陆雨课堂都要修改-->确保sessionid正确 || 不会填写请前往：http://lyck6.cn/help
    ,sessionid : ''//这个参数每次登陆都要更改<-->这个参数可以通过f12开发人员选项Application中的Cookies中获取这个参数
    ,classid : '' //这个参数需要你自己创建一个课程，然后点开课程，地址url栏有对应得班级id

    // 1代表开启，0代表关闭
    ,video: 1 // 视频支持后台、切换窗口不暂停，支持多视频，默认开启
    ,work: 1 // 自动答题功能(章节测验)，作业需要手动开启查询，高准确率，默认开启
    ,audio: 1 // 音频自动播放，与视频功能共享vol和rate参数，默认开启
    ,book: 1 // 图书阅读任务点，非课程阅读任务点，默认开启
    ,docs: 1 // 文档阅读任务点，PPT类任务点自动完成阅读任务，默认开启

    // 本区域参数，上方为任务点功能，下方为独立功能
    ,jump: 1 // 自动切换任务点、章节、课程(需要配置course参数)，默认开启
    ,read: '10' // 挂机课程阅读时间，单位是分钟，'65'代表挂机65分钟，请手动打开阅读页面，默认'10'分钟
    ,face: 0 // 解除面部识别(不支持二维码类面部采集)，此功能仅为临时解除，默认关闭
    ,copy: 0 // 自动复制答案到剪贴板，也可以通过手动点击按钮或答案进行复制，默认关闭
    ,total: 1 // 显示课程进度的统计数据，在学习进度页面的上方展示，默认关闭

    // 仅开启video(audio)时，修改此处才会生效
    ,line: '公网1' || '流畅' // 视频播放的默认资源线路，此功能适用于系统默认线路无资源，默认'公网1'
    ,http: '标清' // 视频播放的默认清晰度，无效参数则使用系统默认清晰度，默认'标清'
    ,habit: '0' // 限制视频挂机时长，单位是分钟，如需挂机习惯分，可以修改参数为'30'，默认不限制
    ,speed: '1.5' // 进度统计速率，高倍率可以快速完成任务点，设定范围：(0,+∞)，默认'1.5'倍
    ,que: 1 // 屏蔽视频时间点对应的节试题，取消屏蔽则自动切换为模拟点击关闭弹题，默认开启
    ,danmu: 0 // 见面课弹幕，关闭后在网页中无法手动开启，默认关闭

    // 本区域参数，上方为video功能独享，下方为audio功能共享
    ,vol: '0' // 默认音量的百分数，设定范围：[0,100]，'0'为静音，默认'0'
    ,rate: '1' // 视频播放默认倍率，参数范围0∪[0.0625,16]，'0'为秒过，默认'1'倍

    // 仅开启work时，修改此处才会生效
    ,auto: 1 // 答题完成后自动提交，默认开启 改为0关闭
    ,none: 0 // 无匹配答案时随机选择一个选项做答，关闭后若题目无匹配答案则会暂时保存已作答的题目，默认关闭
    ,scale: 0 // 富文本编辑器高度自动拉伸，用于文本类题目，答题框根据内容自动调整大小，默认关闭
    ,hide: 0 // 不加载答案搜索提示框，键盘↑和↓可以临时移除和加载，默认关闭

    // 仅开启jump时，修改此处才会生效
    ,course: 0 // 当前课程完成后自动切换课程，仅支持按照根目录课程顺序切换，默认关闭
    ,lock: 1 // 跳过未开放(图标是锁)的章节，即闯关模式或定时发放的任务点，默认开启

    // 自动登录功能配置区
    ,school: '账号为手机号可以不修改此参数' // 学校/单位/机构码，要求完整有效可查询，例如'清华大学'
    ,username: '' // 学号/工号/借书证号(邮箱/手机号/账号)，例如'2018010101'，默认''
    ,password: '' // 密码，例如'123456'，默认''
},
_self = unsafeWindow,
url = location.pathname,
top = _self,
userSetting;

GM_getValue('userSetting') ? userSetting = GM_getValue('userSetting') : GM_setValue('userSetting',setting)

if (url != '/studyApp/studying' && top != _self.top && !(location.host.match('yuketang') || location.host.match('xuetangx'))) document.domain = location.host.replace(/.+?\./, '');

try {
    while (top != _self.top) {
        top = top.parent.document ? top.parent : _self.top;
        if (top.location.pathname == '/mycourse/studentstudy') break;
    }
} catch (err) {
    top = _self;
}
var parent = _self == top ? self : _self.parent,
Ext = _self.Ext || parent.Ext || {},
UE = _self.UE,
vjs = _self.videojs,
xhr = _self.XMLHttpRequest;

String.prototype.toCDB = function() {
    return this.replace(/\s/g, '').replace(/[\uff01-\uff5e]/g, function(str) {
        return String.fromCharCode(str.charCodeAt(0) - 65248);
    }).replace(/[“”]/g, '"').replace(/[‘’]/g, "'").replace(/。/g, '.');
};
var $$ = _self.jQuery || top.jQuery || $;

if(setting.switch) $$('head').append('<link rel="stylesheet" href="https://unpkg.com/element-ui/lib/theme-chalk/index.css">');

var vm = new Vue({
    data: {
        topic: '',
        content: '',
        result: '',
        msg: ''
    },
    methods: {
        Toreply() {
            this.topic = setting.topic;
            this.content = this.topic[Math.floor((Math.random() * this.topic.length))];
            return this.content;
        },
        openSuccess() {
            this.$message({
                message: '已自动帮你自动回复一条讨论，内容为：' + this.content,
                type: 'success'
            });
        },
        openError() {
            this.$message.error('自动回复讨论失败,请关闭浏览器重新打开超星');
        },
        getQueryVariable(variable) {
            var query = window.location.search.substring(1);
            var vars = query.split("&");
            for (var i = 0; i < vars.length; i++) {
                var pair = vars[i].split("=");
                if (pair[0] == variable) {
                    return pair[1];
                }
            }
            return (false);
        },
        submitTopic() {
            $$.ajax({
                type: "POST",
                url: "https://mooc1-1.chaoxing.com/bbscircle/grouptopic/publish",
                headers: {
                    'Content-type': 'application/x-www-form-urlencoded'
                },
                data: {
                    courseId: GM_getValue('courseId'),
                    clazzid: GM_getValue('clazzid'),
                    content: this.Toreply()
                },
                success: function(data) {
                    try{
                        data = JSON.parse(data);
                    }catch(err){
                        vm.openError();
                    }
                    if (data.result) {
                        vm.openSuccess();
                    } else {
                        vm.openError();
                    }
                }
            })
        },
        setValue(){
            GM_setValue('courseId',this.getQueryVariable('courseId'))
            GM_setValue('clazzid',this.getQueryVariable('clazzid'))
        }
    }
})

$$(document).keydown(function(event) {
    if (event.keyCode == 38) {
        setting.div.detach();
    } else if (event.keyCode == 40) {
        setting.div.appendTo('body');
    }
});

setting.normal = '';
setting.queue = setting.curs = [];
setting.job = [':not(*)'];
setting.video && setting.job.push('iframe[src*="/video/index.html"]');
setting.work && setting.job.push('iframe[src*="/work/index.html"]');
setting.audio && setting.job.push('iframe[src*="/audio/index.html"]');
setting.book && setting.job.push('iframe[src*="/innerbook/index.html"]');
setting.docs && setting.job.push('iframe[src*="/ppt/index.html"]', 'iframe[src*="/pdf/index.html"]');
setting.tip = !setting.queue || top != _self && jobSort($$ || Ext.query);
setting.type = {
    '单选题': 0,
    '多选题': 1,
    '填空题': 2,
    '问答题': 4,
    '分析题/解答题/计算题/证明题': 5,
    '阅读理解（选择）/完型填空': 9,
    '判断题': 3
};

if (url == '/mycourse/studentcourse'){
    vm.setValue();
} else if (url == '/mycourse/studentstudy') {
    setting.switch && vm.submitTopic();
    _self.checkMobileBrowerLearn = $$.noop;
    var classId = location.search.match(/cla[zs]{2}id=(\d+)/i)[1] || 0,
    courseId = _self.courseId || location.search.match(/courseId=(\d+)/i)[1] || 0;
    setting.lock || $$('#coursetree').on('click', '[onclick*=void], [href*=void]', function() {
        _self.getTeacherAjax(courseId, classId, $$(this).parent().attr('id').slice(3));
    });
} else if (url == '/ananas/modules/video/index.html' && setting.video) {
    if (setting.review) _self.greenligth = Ext.emptyFn;
    checkPlayer(_self.supportH5Video());
} else if (url == '/work/doHomeWorkNew' || url == '/api/work' || url == '/work/addStudentWorkNewWeb') {
    if (!UE) {
        var len = ($$ || Ext.query || Array)('font:contains(未登录)', document).length;
        setTimeout(len == 1 ? top.location.reload : parent.greenligth, setting.time);
    } else if (setting.work) {
        setTimeout(relieveLimit, 0);
        beforeFind();
    }
} else if (url == '/ananas/modules/audio/index.html' && setting.audio) {
    if (setting.review) _self.greenligth = Ext.emptyFn;
    _self.videojs = hookAudio;
    hookAudio.xhr = vjs.xhr;
} else if (url == '/ananas/modules/innerbook/index.html' && setting.book && setting.tip) {
    setTimeout(function() {
        _self.setting ? _self.top.onchangepage(_self.getFrameAttr('end')) : _self.greenligth();
    }, setting.time);
} else if (url.match(/^\/ananas\/modules\/(ppt|pdf)\/index\.html$/) && setting.docs && setting.tip) {
    setTimeout(function() {
        _self.setting ? _self.finishJob() : _self.greenligth();
    }, setting.time);
    frameElement.setAttribute('download', 1);
} else if (url == '/knowledge/cards') {
    $$ && checkToNext();
} else if (url.match(/^\/(course|zt)\/\d+\.html$/)) {
    setTimeout(function() {
        +setting.read && _self.sendLogs && $$('.course_section:eq(0) .chapterText').click();
    }, setting.time);
} else if (url == '/ztnodedetailcontroller/visitnodedetail') {
    setting.read *= 60 / $$('.course_section').length;
    setting.read && _self.sendLogs && autoRead();
} else if (url == '/mycourse/studentcourse') {
    var gv = location.search.match(/d=\d+&/g);
    setting.total && $$('<a>', {
        href: '/moocAnalysis/chapterStatisticByUser?classI' + gv[1] + 'courseI' + gv[0] + 'userId=' + _self.getCookie('_uid') + '&ut=s',
        target: '_blank',
        title: '点击查看章节统计',
        style: 'margin: 0 25px;',
        html: '本课程共' + $$('.icon').length + '节，剩余' + $$('em:not(.openlock)').length + '节未完成'
    }).appendTo('.zt_logo').parent().width('auto');
} else if (url.match(/^\/visit\/(courses|interaction)$/)) {
    setting.face && $$('.zmodel').on('click', '[onclick^=openFaceTip]', DisplayURL);
} else if (location.host.match(/^passport2/)) {
    setting.username && getSchoolId();
} else if (location.hostname == 'i.mooc.chaoxing.com' && location.pathname.match(/space/)) {
    _self.layui.use('layer', function() {
        this.layer.open({
            content: '使用过程中会上传您的账户信息（包括昵称、ID、手机号等）以识别用户防止恶意爬题<br>初始用户赠送50积分，可用于使用token题库答题<br>不同意请勿使用脚本',
            title: '用户协议',
            btn: ['我同意'],
            btn1:function(){
                window.open(document.getElementsByClassName("manageBtn")[0].href)
                layer.closeAll();
            },
            offset: 't', closeBtn: 0});
    });
} else if(location.pathname == '/settings/info'){
    uploadInfo(getInfo())
    setTimeout(function(){window.close();}, 350)
} else if (url == '/widget/pcvote/goStudentVotePage') {
    $$(':checked').click();
    $$('.StudentTimu').each(function(index) {
        var ans = _self.questionlist[index].answer;
        $$(':radio, :checkbox', this).each(function(num) {
            ans[num].isanswer && this.click();
        });
        $$(':text', this).val(function(num) {
            return $$(ans[num].content).text().trim();
        });
    });
} else if (url == '/work/selectWorkQuestionYiPiYue') {
    submitAnswer();
    setting.switch && vm.submitTopic();
} else if (url.match('/videoList')) {
    $$.tmDialog.alert({content: '2.X版本已取消支持旧版界面', title: '智慧树网课助手提示'});
} else if (url == '/videoStudy.html') {
    setting.habit *= 6E4;
    setting.video && ZHShookVideo(_self.vjsComponent, 1);
    setting.jump && setInterval(ZHScheckToNext, setting.time);
} else if (url == '/portals_h5/2clearning.html') {
    setting.video && ZHShookVideo(_self.vjsComponent, 2);
    setting.jump && setInterval(ZHScheckToNext, setting.time);
} else if (url == '/live/vod_room.html') {
    setting.video && ZHShookVideo(_self.vjsComponent);
    setting.jump && setInterval(ZHScheckToNext, setting.time, 1);
} else if (location.hostname.match('examh5')) {
    setTimeout(ZHSrelieveLimit, 100, document);
    if ((location.hash.match(/dohomework|doexamination/)) && setting.work) ZHSbeforeFind();
    $$(window).on('hashchange', function() {
        setting.work && location.reload();
    });
} else if (url.match('/sourceLearning')) {
    setting.video && ZHShookVideo(_self.vjsComponent, 3);
    setting.jump && setInterval(function(){let arr = ['fanzhuan',$$('#sourceTree').find('.file-item').map(function(i){if($$(this).find('.icon-finish').length == 0){return i}})[0]];ZHScheckToNext(arr)}, setting.time);
} else if (url == '/shareCourse/questionDetailPage') {
    setTimeout(ZHSrelieveLimit, 100, document);
    $$('textarea[oncut]').each(function() {
        setTimeout(ZHSrelieveLimit, 100, this);
    });
} else if(url.match('homeworkDetail')){
    setTimeout(function(){$$('.stuQuestionDownBtn').click();},500)
}else if ((url.match('exerciseList') || location.pathname.match('homeworkQ') || location.pathname.match('examexercise')) && setting.work) {
    setTimeout(function(){
        if(location.pathname.match('exerciseList') || location.pathname.match('examexercise')){
            setTimeout(ZHSrelieveLimit, 100, document);
            ZHSbeforeFind()
        }else if(location.pathname.match('homeworkQ')){
            ZhiHuiShuSubmitAnswer();
        }
    },2000)
} else if (url == '/exam/test/reVersionTestStartNew'){
    Exam();
} else if (url=='/exam/test/reVersionPaperMarkContentNew'){
   SubmitExamAnswer();
} else if (location.host.match('yuketang') || location.host.match('xuetangx')){
    setting.div = $$(
        '<div style="box-shadow: darkgrey 10px 10px 10px 5px;border: 0.5px solid #666;width: 330px;background-color: #B0E2FF; position: fixed; top: 0px; right: 0; z-index: 99999;">' +
        '<span style="font-size: medium;"></span>' +
        '<div style="color: bule;background: #B0E2FF;;font-size: 15px;margin-bottom: 1%;">雨课堂答题助手已启用<br>请前往【章节测验/考试/试卷】刷新网页会自动搜索答案<br>若无答案请刷新页面重新加载</div>' +
        '</div>' +
        '</div>'
   ).appendTo('#app')
    if(location.pathname.match('studentQuiz') || location.pathname.match('exam') || location.pathname.match('result')){
        YKTfindAnswer()
    }else if (url.match(/homework/)){
        YuKeTangBeforeFind()
    }else if (url.match(/studycontent/)){
        setting.div.detach();
    }
}else if(url == '/study/workExam/homeWork/preview.html' || url == '/study/workExam/testWork/preview.html' || url == '/study/workExam/onlineExam/preview.html'){
    ZhiJiaoYunBeforeFind()
}else if(url == '/study/workExam/homeWork/history.html' || url == '/study/workExam/testWork/history.html' || url == '/study/workExam/onlineExam/history.html'){
    setTimeout(ZhiJiaoYunSubmitAnswer,1000)
}else if(url == '/study/directory/dir_course.html'){
    setTimeout(function(){
        if($('.view_text_con').find('.preview_cm').find('.answer').text()){
            GreenZhiJiaoYunSubmitAnswer(getGreenZhiJiaoYunData());
        }else if ($('.subpaper').text().match('提交答案')){
            ZhiJiaoYunBeforeFind()
        }
    },3000)
}else if (url == '/study/works/works.html'){
    ZhiJiaoYunBeforeFind()
    setTimeout(getGreenZhiJiaoYunData,2000);
}else if (url.match('examTest/stuExamList')){
    var Intv = setInterval(function(){
        if($('#submit_exam').length){
            YiBinBeforeFind();
            clearInterval(Intv);
            delete Intv;
        }
    },2000)
}

function sleep(delay) {
    for(var t = Date.now(); Date.now() - t <= delay;);
}
function getIframe(tip, win, job) {
    if (!$$) return Ext.get(frameElement || []).parent().child('.ans-job-icon') || Ext.get([]);
    do {
        win = win ? win.parent : _self;
        job = $$(win.frameElement).prevAll('.ans-job-icon');
    } while (!job.length && win.parent.frameElement);
    return tip ? win : job;
}

function jobSort($$) {
    var fn = $$.fn ? [getIframe(1), 'length'] : [self, 'dom'],
    sel = setting.job.join(', :not(.ans-job-finished) > .ans-job-icon' + setting.normal + ' ~ ');
    if ($$(sel, fn[0].parent.document)[0] == fn[0].frameElement) return true;
    if (!getIframe()[fn[1]] || getIframe().parent().is('.ans-job-finished')) return null;
    setInterval(function() {
        $$(sel, fn[0].parent.document)[0] == fn[0].frameElement && fn[0].location.reload();
    }, setting.time);
}

function checkPlayer(tip) {
    _self.videojs = hookVideo;
    hookVideo.xhr = vjs.xhr;
    Ext.isSogou = Ext.isIos = Ext.isAndroid = false;
    var data = Ext.decode(_self.config('data')) || {};
    delete data.danmaku;
    data.doublespeed = 1;
    frameElement.setAttribute('data', Ext.encode(data));
    if (tip) return;
    _self.supportH5Video = function() {return true;};
    alert('此浏览器不支持html5播放器，请更换浏览器');
}

function hookVideo() {
    setting.switch && vm.submitTopic();
    _self.alert = console.log;
    var config = arguments[1],
    line = Ext.Array.filter(Ext.Array.map(config.playlines, function(value, index) {
        return value.label == setting.line && index;
    }), function(value) {
        return Ext.isNumber(value);
    })[0] || 0,
    http = Ext.Array.filter(config.sources, function(value) {
        return value.label == setting.http;
    })[0];
    config.playlines.unshift(config.playlines[line]);
    config.playlines.splice(line + 1, 1);
    config.plugins.videoJsResolutionSwitcher.default = http ? http.res : 360;
    config.plugins.studyControl.enableSwitchWindow = 1;
    config.plugins.timelineObjects.url = '/richvideo/initdatawithviewer?';
    config.plugins.seekBarControl.enableFastForward = 1;
    if (!setting.queue) delete config.plugins.studyControl;
    var player = vjs.apply(this, arguments),
    a = '<a href="https://d0.ananas.chaoxing.com/download/' + _self.config('objectid') + '" target="_blank">',
    img = '<img src="https://d0.ananas.chaoxing.com/download/e363b256c0e9bc5bd8266bf99dd6d6bb" style="margin: 6px 0 0 6px;">';
    player.volume(Math.round(setting.vol) / 100 || 0);
    Ext.get(player.controlBar.addChild('Button').el_).setHTML(a + img + '</a>').dom.title = '下载视频';
    player.on('loadstart', function() {
        setting.tip && this.play().catch(Ext.emptyFn);
        this.playbackRate(setting.rate > 16 || setting.rate < 0.0625 ? 1 : setting.rate);
    });
    player.one(['loadedmetadata', 'firstplay'], function() {
        setting.two = setting.rate === '0' && setting.two < 1;
        setting.two && config.plugins.seekBarControl.sendLog(this.children_[0], 'ended', Math.floor(this.cache_.duration));
    });
    player.on('ended', function() {
        Ext.fly(frameElement).parent().addCls('ans-job-finished');
    });
    return player;
}

function hookAudio() {
    setting.switch && vm.submitTopic();
    _self.alert = console.log;
    var config = arguments[1];
    config.plugins.studyControl.enableSwitchWindow = 1;
    config.plugins.seekBarControl.enableFastForward = 1;
    if (!setting.queue) delete config.plugins.studyControl;
    var player = vjs.apply(this, arguments),
    a = '<a href="https://d0.ananas.chaoxing.com/download/' + _self.config('objectid') + '" target="_blank">',
    img = '<img src="https://d0.ananas.chaoxing.com/download/e363b256c0e9bc5bd8266bf99dd6d6bb" style="margin: 6px 0 0 6px;">';
    player.volume(Math.round(setting.vol) / 100 || 0);
    player.playbackRate(setting.rate > 16 || setting.rate < 0.0625 ? 1 : setting.rate);
    Ext.get(player.controlBar.addChild('Button').el_).setHTML(a + img + '</a>').dom.title = '下载音频';
    player.on('loadeddata', function() {
        setting.tip && this.play().catch(Ext.emptyFn);
    });
    player.one('firstplay', function() {
        setting.rate === '0' && config.plugins.seekBarControl.sendLog(this.children_[0], 'ended', Math.floor(this.cache_.duration));
    });
    player.on('ended', function() {
        Ext.fly(frameElement).parent().addCls('ans-job-finished');
    });
    return player;
}

function relieveLimit() {
    if (setting.scale) _self.UEDITOR_CONFIG.scaleEnabled = false;
    $$.each(UE.instants, function() {
        var key = this.key;
        this.ready(function() {
            this.destroy();
            UE.getEditor(key);
        });
    });
}

function beforeFind() {
    setting.regl = parent.greenligth || $$.noop;
    if ($$.type(parent._data) == 'array') return setting.regl();
    setting.div = $$(
        '<div style="box-shadow: darkgrey 10px 10px 10px 5px;border: 0.5px solid #666;width: 330px;background-color: #FF7F00; position: fixed; top: 100px; right: 0; z-index: 99999;">' +
       '<span style="font-size: medium;"></span>' +
       '<img src="http://lyck6.cn/img/6.png" width="100%" />'+
        '设置token(手机号):<input id="phone" type="text name="token" value='+GM_getValue('phone')+'>'+
        '<button id="button" type="submit">确定</button>'+
        '<div style="color: bule;background: #B0E2FF;;font-size: 15px;margin-bottom: 1%;">目前默认搜索|'+(userSetting.option ? 'token题库':'免费题库')+'<br>更改默认设置请修改脚本参数option<br>临时更改点击下方按钮</div>' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 60px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">暂停答题</button> ' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 110px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">' + (setting.auto ? '取消本次自动提交' : '开启本次自动提交') + '</button>' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 110px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">' + (userSetting.option ? '取消请求token题库' : '开启请求token题库') + '</button>' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 60px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">重新查询</button>' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 60px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">折叠面板</button>' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 70px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">获取积分</button>' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 70px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">手动注册</button>' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 70px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">拓展功能</button>' +
        '<div style="max-height: 300px; overflow-y: auto;">' +
                '<table border="1"  style="font-size: 12px;color:black;background-color:#FF7F00;">' +
                    '<thead>' +
                        '<tr>' +
                            '<th style="width: 25px; min-width: 25px;">题号</th>' +
                            '<th style="width: 60%; min-width: 130px;">题目（点击可复制）</th>' +
                            '<th style="min-width: 130px;">答案（点击可复制）</th>' +
                        '</tr>' +
                    '</thead>' +
                    '<tfoot style="display: none;">' +
                        '<tr>' +
                            '<th colspan="3">答案提示框 已折叠</th>' +
                        '</tr>' +
                    '</tfoot>' +
                    '<tbody style="overflow-y: scroll;80px;">'+
                        '<tr>' +
                            '<td colspan="3" style="display: none;"></td>' +
                        '</tr>' +
                    '</tbody>' +
                '</table>' +
            '</div>' +
        '</div>'
    ).appendTo('body').on('click', 'button, td', function() {
        var len = $$(this).prevAll('button').length;
        if (this.nodeName == 'TD') {
            $$(this).prev().length && GM_setClipboard($$(this).text());
        } else if (!$$(this).siblings().length) {
            $$(this).parent().text('正在搜索|防止失联建议加群1102188986');
            setting.num++;
        } else if (len === 0){
            GM_setValue('phone',$$("#phone").val())
        }else if (len === 1) {
            if (setting.loop) {
                clearInterval(setting.loop);
                delete setting.loop;
                len = ['已暂停搜索'+(+userSetting.option ? 'token题库':'免费题库'), '继续答题'];
            } else {
                setting.loop = setInterval(findAnswer, setting.time);
                len = ['正在搜索'+(+userSetting.option ? 'token题库':'免费题库'), '暂停答题'];
            }
            setting.div.children('div:eq(0)').html(function() {
                return $$(this).data('html') || len[0];
            }).removeData('html');
            $$(this).html(len[1]);
        } else if (len == 2) {
            setting.auto = !setting.auto;
            $$(this).html(setting.auto ? '取消本次自动提交' : '开启本次自动提交');
        } else if (len == 3) {
             userSetting.option = !userSetting.option;
            $$(this).html(userSetting.option ? '取消请求token题库' : '开启请求token题库');
            GM_setValue('userSetting',userSetting)
        } else if (len == 4) {
             parent.location.reload();
        }else if (len == 5) {
            setting.div.find('tbody, tfoot').toggle();
        }else if (len == 6) {
            window.open("http://lyck6.cn/pay/index.php?&phone="+ GM_getValue('phone'));
        } else if (len == 7){
           window.open('http://lyck6.cn/api/regist.php?phone='+ GM_getValue('phone'))
        } else if (len == 8){
           window.open('http://user.lyck6.cn')
        }
    }).find('table, td, th').css('border', '1px solid').end().detach(setting.hide ? '*' : 'html');
    setting.lose = setting.num = 0;
    setting.data = parent._data ;
    setting.over = '<button style="background-color: #4CAF50;/* Green */border: none;margin: 1%;color: white;width: 80px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 16px;">跳过此题</button>';
    setting.curs = $$('script:contains(courseName)', top.document).text().match(/courseName:\'(.+?)\'|$/)[1] || $$('h1').text().trim() || '无';
    setting.loop = setInterval(findAnswer, setting.time);
    setting.review ? setting.tip = false : '';
    var tip = ({undefined: '任务点排队中', null: '等待切换中'})[setting.tip];
    tip && setting.div.children('div:eq(0)').data('html', tip).siblings('button:eq(1)').click();
    setting.switch && vm.submitTopic();
}

function findAnswer() {
    if (setting.num >= $$('.TiMu').length) {
        var arr = setting.lose ? ['共有 <font color=red>' + setting.lose + '</font> 道题目待完善（已深色标注）', saveThis] : ['答题已完成', submitThis];
        setting.div.children('div:eq(0)').data('html', arr[0]).siblings('button:eq(1)').hide().click();
        return setTimeout(arr[1], setting.time);
    }
    let $$TiMu = $$('.TiMu').eq(setting.num),
        postData = {
        question: filterImg($$TiMu.find('.Zy_TItle:eq(0) .clearfix')).replace(/^【.*?】\s*/, '').replace(/\s*（\d+\.\d+分）$/, '').replace(/[(]\s*[)]。$/,'').replace(/（\s*）。$/,'').replace(/[(]\s*[)]$/,'').replace(/（\s*）$/,''),
        type: $$TiMu.find('input[name^=answertype]:eq(0)').val() || 10,
        option: filterImg($$('.TiMu').find('.Zy_ulTop').eq(setting.num), this).replace(/\s+/g,' ') || '',
    }
    GM_xmlhttpRequest({
        method: 'POST',
        url : 'http:/user.lyck6.cn/api/query/' + (userSetting.option ? (GM_getValue('phone') || setting.token || 'undefined') : '0'),
        headers: {
            'Content-type': 'application/x-www-form-urlencoded',
        },
        data: 'question=' + encodeURI(postData.question) + '&option='+ encodeURI(postData.option) + '&type=' + postData.type,
        timeout: setting.time,
        onload: function(xhr) {
            if (!setting.loop) {
            } else if (xhr.status == 200) {
                var obj = $$.parseJSON(xhr.responseText) || {};
                if (obj.code == 200) {
                    userSetting.option ? setting.div.children('div:eq(0)').text('正在搜索token题库--当前积分剩余：'+obj.data.num):setting.div.children('div:eq(0)').text('正在搜索免费题库|防止失联建议加群'+obj.data.qun);
                    var td = '<td style="border: 1px solid" colspan="1" font-size: 1.1em;text-align: left;background-color: #A7C942;color: #ffffff;',
                    answer = String(obj.data.answer).replace(/&/g, '&amp;').replace(/<(?!img)/g, '&lt;');
                    obj.data.answer = /^http/.test(answer) ? '<img src="' + obj.data.answer + '">' : obj.data.answer;
                    $$(
                        '<tr>' +
                            td + ' text-align: center;">' + $$TiMu.find('.Zy_TItle:eq(0) i').text().trim() + '</td>' +
                            td + '" title="点击可复制">' + (postData.question.match('<img') ? postData.question : postData.question.replace(/&/g, '&amp;').replace(/</g, '&lt')) + '</td>' +
                            td + '" title="点击可复制">' + obj.data.answer +'</td>' +
                        '</tr>'
                    ).appendTo(setting.div.find('tbody')).css('background-color', fillAnswer($$TiMu.find('ul:eq(0)').find('li'), obj, postData) ? '' : 'rgba(0, 150, 136, 0.6)');
                   setting.num++;
                } else if(obj.code == 110 || obj.code == 104){
                    setting.div.children('div:eq(0)').html(obj.msg);
                } else if (obj.code == 102 || obj.code == 305){
                    setting.div.children('div:eq(0)').data('html', obj.msg).siblings('button:eq(1)').click();
                    window.open('http://lyck6.cn/api/regist.php')
                } else{
                    setting.div.children('div:eq(0)').html('发现未知异常，请联系QQ1666888816报告反馈bug').siblings('button:eq(1)').click();;
                }
                //setting.div.children('span').html(obj.msg || '');
            } else if (xhr.status == 403) {
                setting.div.children('div:eq(0)').data('html', '由于你的请求过于频繁，您的ip已被封<br>10分钟后自动解封<br>或者使用token答题不限制请求次数').siblings('button:eq(1)').click();
            } else if (xhr.status == 404) {
                setting.div.children('div:eq(0)').data('html', '最新版已发布！请点击油猴按钮【用户脚本检查更新】完成更新！').siblings('button:eq(1)').click();
            }else {
                setting.div.children('div:eq(0)').html('发现未知异常，请联系QQ1666888816处理');
            }
        },
        ontimeout: function() {
            setting.loop && setting.div.children('div:eq(0)').html(setting.over + '正在链接到云端，请稍后....<br>如果长时间链接不上请联系QQ1666888816');
        }
    });
}

function fillAnswer($$li, obj, postData) {
    var $$input = $$li.find(':radio, :checkbox'),
    str = String(obj.data.answer).toCDB(),
    data = str.split(/#|\x01|\|/),
    state = setting.lose;
    obj.data.success && $$input.each(function(index) {
        if (this.value == 'true') {
            data.join().match(/(^|,)(正确|是|对|√|T|ri)(,|$)/) && this.click();
        } else if (this.value == 'false') {
            data.join().match(/(^|,)(错误|否|错|×|F|wr)(,|$)/) && this.click();
        } else {
            var tip = filterImg($$li.eq(index).find('.after')).toCDB();
            Boolean($$.inArray(tip, data) + 1 || (postData.type == '1' && str.indexOf(tip) + 1)) == this.checked || this.click();
        }
    }).each(function() {
        if (!/^A?B?C?D?E?F?G?$/.test(str)) return false;
        Boolean(str.match(this.value)) == this.checked || this.click();
    });
    if (postData.type.match(/^[013]$/)) {
        $$input.is(':checked') || (setting.none ? ($$input[Math.floor(Math.random() * $$input.length)] || $$()).click() : setting.lose++);
    } else if (postData.type.match(/^(2|[4-9]|1[08])$/)) {
        data = String(obj.data.answer).split(/#|\x01|\|/);
        str = $$li.end().find('textarea').each(function(index) {
            index = (obj.code == 200 && data[index]) || '';
            obj.data.success ? UE.getEditor(this.name).setContent(index.trim()) : '';
        }).length;
        (obj.data.success && data.length == str) || setting.none || setting.lose++;
    } else {
        setting.none || setting.lose++;
    }
    return state == setting.lose ? true : reportProblem(postData);
}

function saveThis() {
    if (!setting.auto) return setTimeout(saveThis, setting.time);
    setting.div.children('button:lt(3)').hide().eq(1).click();
    _self.alert = console.log;
    $$('#tempsave').click();
    setting.regl();
}

function submitThis() {
    if (!setting.auto) {
    } else if (!$$('.Btn_blue_1:visible').length) {
        setting.div.children('button:lt(3)').hide().eq(1).click();
        return setting.regl();
    } else if ($$('#confirmSubWin:visible').length) {
        var btn = $$('#tipContent + * > a').offset() || {top: 0, left: 0},
        mouse = document.createEvent('MouseEvents');
        btn = [btn.left + Math.ceil(Math.random() * 46), btn.top + Math.ceil(Math.random() * 26)];
        mouse.initMouseEvent('click', true, true, document.defaultView, 0, 0, 0, btn[0], btn[1], false, false, false, false, 0, null);
        _self.event = $$.extend(true, {}, mouse);
        delete _self.event.isTrusted;
        _self.form1submit();
    } else {
        $$('.Btn_blue_1')[0].click();
    }
     setTimeout(submitThis, Math.ceil(setting.time * Math.random()) * 2);
	 submitAnswer();
}

function checkToNext() {
    var $$tip = $$(setting.job.join(', '), document).prevAll('.ans-job-icon' + setting.normal);
    setInterval(function() {
        $$tip.parent(':not(.ans-job-finished)').length || setting.jump && toNext();
    }, setting.time);
}

function toNext() {
    var $$cur = $$('#cur' + $$('#chapterIdid').val()),
    $$tip = $$('span.currents ~ span'),
    sel = setting.review ? 'html' : '.blue';
    if (!$$cur.has(sel).length && $$tip.length) return $$tip.eq(0).click();
    $$tip = $$('.roundpointStudent, .roundpoint').parent();
    $$tip = $$tip.slice($$tip.index($$cur) + 1).not(':has(' + sel + ')');
    $$tip.not(setting.lock ? ':has(.lock)' : 'html').find('span').eq(0).click();
    $$tip.length || setting.course && switchCourse();
}

function switchCourse() {
    GM_xmlhttpRequest({
        method: 'GET',
        url: '/visit/courses/study?isAjax=true&fileId=0&debug=',
        headers: {
            'Referer': location.origin + '/visit/courses',
            'X-Requested-With': 'XMLHttpRequest'
        },
        onload: function(xhr) {
            var list = $$('h3 a[target]', xhr.responseText).map(function() {
                return $$(this).attr('href');
            }),
            index = list.map(function(index) {
                return this.match(top.courseId) && index;
            }).filter(function() {
                return $$.isNumeric(this);
            })[0] + 1 || 0;
            setting.course = list[index] ? goCourse(list[index]) : 0;
        }
    });
}

function goCourse(url) {
    GM_xmlhttpRequest({
        method: 'GET',
        url: url,
        onload: function(xhr) {
            $$.globalEval('location.href = "' + $$('.articlename a[href]', xhr.responseText).attr('href') + '";');
        }
    });
}

function autoRead() {
    $$('html, body').animate({
        scrollTop: $$(document).height() - $$(window).height()
    }, Math.round(setting.read) * 1E3, function() {
        $$('.nodeItem.r i').click();
    }).one('click', '#top', function(event) {
        $$(event.delegateTarget).stop();
    });
}

function DisplayURL() {
    _self.WAY.box.hide();
    var $$li = $$(this).closest('li');
    $$.get('/visit/goToCourseByFace', {
        courseId: $$li.find('input[name=courseId]').val(),
        clazzId: $$li.find('input[name=classId]').val()
    }, function(data) {
        $$li.find('[onclick^=openFaceTip]').removeAttr('onclick').attr({
            target: '_blank',
            href: $$(data).filter('script:last').text().match(/n\("(.+?)"/)[1]
        });
        alert('本课程已临时解除面部识别');
    }, 'html');
}

function getSchoolId() {
    var school = /^1\d{10}$/.test(setting.username) ? '' : setting.school;
    if (!isNaN(school)) return setTimeout(toLogin, setting.time, school);
    if (school == '账号为手机号可以不修改此参数') return alert('请修改school参数');
    $$.getJSON('/org/searchUnis?filter=' + encodeURI(school) + '&product=44', function(data) {
        if (!data.result) return alert('学校查询错误');
        var msg = $$.grep(data.froms, function(value) {
            return value.name == school;
        })[0];
        msg ? setTimeout(toLogin, setting.time, msg.schoolid) : alert('学校名称不完整');
    });
}

function toLogin(fid) {
    GM_xmlhttpRequest({
        method: 'GET',
        url: '/api/login?name=' + setting.username + '&pwd=' + setting.password + '&schoolid=' + fid + '&verify=0',
        onload: function(xhr) {
            var obj = $$.parseJSON(xhr.responseText) || {};
            obj.result ? location.href = decodeURIComponent($$('#ref, #refer_0x001').val()) : alert(obj.errorMsg || 'Error');
        }
    });
}

function filterImg(dom) {
  return $$(dom).clone().find("img[src]").replaceWith(function () {
      return $$("<p></p>").text('<img src="' + $$(this).attr("src") + '">');
    }).end().find("iframe[src]").replaceWith(function () {
      return $$("<p></p>").text('<iframe src="' + $$(this).attr("src") + '"></irame>');
    }).end().text().trim();
}

function ZHShookVideo(Hooks, tip) {
    _self.vjsComponent = function() {
        var config = arguments[0],
        options = config.options,
        line = $$.map(options.sourceSrc.lines, function(value) {
            return value.lineName.replace('标准', '高清');
        }),
        vol = setting.vol > 100 ? 100 : setting.vol,
        rate = tip == 3 ? [1, 1.25, 1.5, 2, 2.5, 3] : [1, 1.25, 1.5];
        vol = Math.round(vol) / 100;
        options.volume = vol > 0 ? vol : 0;
        options.autostart = true;
        setting.speed = setting.speed > 0 ? +setting.speed : 1;
        options.rate = $$.inArray(setting.speed, rate) < 0 ? options.rate : setting.speed;
        tip && config.callback.playbackRate(setting.speed);
        options.chooseLine = $$.inArray(setting.line, line) + 1 || options.chooseLine + 1;
        options.src = options.sourceSrc.lines[--options.chooseLine].lineUrl || options.src;
        if (!setting.danmu) {
            config.defOptions.control.danmuBtn = false;
            delete options.control.danmuBtn;
        }
        Hooks.apply(this, arguments);
        config.player.on('loadstart', function() {
            this.loop(true);
            this.play();
            $$('.speedBox span').text('X ' + setting.speed);
        });
    };
    $$(document).on('click', '.definiLines b', function() {
        setting.line = ({xiaonei: '校内', line1gq: '高清', line1bq: '流畅'})[this.classList[0]];
    }).on('mouseup click', function() {
        setting.vol = _self.PlayerStarter.playerArray[0].player.cache_.volume * 100;
    }).on('click', '.speedList div', function() {
        setting.speed = $$(this).attr('rate');
    });
    if (tip != 1) return;
    setting.tip = setting.habit && setInterval(totalTime, setting.time);
    setInterval(doTest, 1E3);
    _self.XMLHttpRequest = setting.que ? function() {
        var ajax = new xhr(),
        open = ajax.open;
        ajax.open = function(method, url) {
            if (url.match('/loadVideoPointerInfo')) method = 'OPTIONS';
            return open.apply(this, arguments);
        };
        return ajax;
    } : xhr;
}

function totalTime() {
    var player = _self.PlayerStarter.playerArray[0].player;
    setting.habit -= player.paused() ? 0 : setting.time;
    if (setting.habit >= 0) return;
    clearInterval(setting.tip);
    player.pause();
    $$.getScript('//cdn.jsdelivr.net/gh/sentsin/layer/dist/layer.js', function() {
        _self.layer.open({content: '已达到挂机限制时间', title: '智慧树网课助手提示', end: function() {
            setting.habit = 0;
        }});
    });
}

function ZHScheckToNext(tip) {
    if (setting.habit < 0) return;
    var $$tip = $$('.video, .lessonItem');
    if ($$('.current_play .time_icofinish').length) {
        $$tip.slice($$tip.index($$('.current_play')) + 1).not(':has(.time_icofinish)').eq(0).click();
    } else if ($$('.lessonItemActive .finish').length) {
        $$tip.slice($$tip.index($$('.lessonItemActive')) + 1).not(':has(.finish)').eq(0).click();
    } else if (tip == 1) {
        $$('.current_player:contains("100%") + li').click();
    } else if ($$('.settleOn .finish').length) {
        tip.slice(tip.index($$('.settleOn')) + 1).not(':has(.finish)').eq(0).find('.file-name').click();
    } else if (Array.isArray(tip) && tip[0] == 'fanzhuan') {
        ($$('#sourceTree').find('.file-item').eq(tip[1]).find('.file-name').text() == $$('#sourceTit').find('span').text().replace('.mp4','')) || $$('#sourceTree').find('.file-item').eq(tip[1]).click()
    }
}
function doTest() {
    if (!$$('.dialog-test').length) {
    } else if (setting.queue.length) {
        $$(setting.queue.shift()).parent().click();
    } else if (!$$('.answer').length) {
        $$('.topic-item').eq(0).click();
    } else if (!$$('.right').length) {
        var tip = $$('.answer span').text().match(/[A-Z]/g) || [];
        if (tip.length == 1) return $$('.topic-option-item:contains(' + tip[0] + ')').click();
        $$('.topic-option-item').each(function() {
            $$.inArray($$(this).text().slice(0, 1), tip) < 0 == $$(this).hasClass('active') && setting.queue.push(this);
        });
    } else if ($$('.btn-next:enabled').length) {
        $$('.btn-next:enabled').click();
    } else {
        $$('.dialog-test .btn').click();
        _self.PlayerStarter.playerArray[0].player.play();
    }
}

function ZHSrelieveLimit(doc) {
    if (!doc.oncut && !doc.onselectstart) return setTimeout(ZHSrelieveLimit, 100, doc);
    doc.oncontextmenu = doc.onpaste = doc.oncopy = doc.oncut = doc.onselectstart = null;
}

function ZHSbeforeFind() {
    setting.div = $$(
        '<div id = "setting" style="box-shadow: darkgrey 10px 10px 10px 5px;border: 0.5px solid #666;width: 300px;background-color: #fdfcf8; position: absolute; top: 0; right: 0; z-index: 99999;">' +
            '<span style="font-size: medium;"></span>' +
            '<img src="http://lyck6.cn/img/6.png" width="100%" />'+
            '设置token(手机号):<input id="phonenum" type="text" name="token" value=' + GM_getValue('phone')+'>'+
            '<button id="button" type="submit">确定</button>'+
            '<div style="color: bule;background: #B0E2FF;font-size: 15px;margin-bottom: 1%;">目前默认搜索|'+(userSetting.option ? 'token题库':'免费题库')+'<br>更改默认设置请修改脚本参数option<br>临时更改点击下方按钮</div>' +
            '<button  style="background-color: #4CAF50;/* Green */border: none;margin: 1%;color: white;width: 60px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">暂停答题</button> ' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 110px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">' + (userSetting.option ? '取消请求token题库' : '开启请求token题库') + '</button>' +
            '<button  style="background-color: #4CAF50;/* Green */border: none;margin: 1%;color: white;width: 60px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">重新查询</button>' +
            '<button  style="background-color: #4CAF50;/* Green */border: none;margin: 1%;color: white;width: 60px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">折叠面板</button>' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 70px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">获取积分</button>' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 70px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">手动注册</button>' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 70px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">拓展功能</button>' +
            '<div style="max-height: 300px; overflow-y: auto;">' +
                '<table border="1"  style="font-size: 12px;color:black;background-color:#FF7F00;">' +
                    '<thead>' +
                        '<tr>' +
                            '<th style="width: 30px; min-width: 30px; font-weight: bold; text-align: center;">题号</th>' +
                            '<th style="width: 60%; min-width: 130px; font-weight: bold; text-align: center;">题目（点击可复制）</th>' +
                            '<th style="min-width: 130px; font-weight: bold; text-align: center;">答案（点击可复制）</th>' +
                        '</tr>' +
                    '</thead>' +
                    '<tfoot style="display: none;">' +
                        '<tr>' +
                            '<th colspan="3" style="font-weight: bold; text-align: center;">答案提示框 已折叠</th>' +
                        '</tr>' +
                    '</tfoot>' +
                    '<tbody>' +
                        '<tr>' +
                            '<td colspan="3" style="display: none;"></td>' +
                        '</tr>' +
                    '</tbody>' +
                '</table>' +
            '</div>' +
        '</div>'
    ).appendTo('body').on('click', 'button, td', function() {
        var len = $$(this).prevAll('button').length;
        if (this.nodeName == 'TD') {
            $$(this).prev().length && GM_setClipboard($$(this).text());
        } else if (len == 0){
            GM_setValue('phone',document.getElementById('phonenum').value)
        } else if (len === 1) {
            if (setting.loop) {
                clearInterval(setting.loop);
                delete setting.loop;
                len = [false, '已暂停搜索'+(userSetting.option ? 'token题库':'免费题库'), '继续答题'];
            } else {
                if(url.match('exerciseList') || location.pathname.match('examexercise')) setting.loop = setInterval(ZhiHuiShuNewFindAnswer, setting.time*2);
                if(location.hash.match(/dohomework|doexamination/) )setting.loop = setInterval(ZHSfindAnswer, setting.time);
                len = [true, '正在搜索'+(userSetting.option ? 'token题库':'免费题库'), '暂停答题'];
            }
            setting.div.find('input').attr('disabled', len[0]);
            setting.div.children('div:eq(0)').html(function() {
                return $$(this).data('html') || len[1];
            }).removeData('html');
            $$(this).html(len[2]);
        } else if (len == 2) {
            userSetting.option = !userSetting.option;
            $$(this).html(userSetting.option ? '取消请求token题库' : '开启请求token题库');
            GM_setValue('userSetting',userSetting)
        } else if (len == 3) {
             location.reload();
        } else if (len == 4) {
             setting.div.find('tbody, tfoot').toggle();
        } else if (len == 5){
            window.open("http://lyck6.cn/pay/index.php?phone=" + GM_getValue('phone'));
        } else if (len == 6){
            window.open('http://lyck6.cn/api/regist.php?phone='+ GM_getValue('phone'))
        } else if (len == 7){
            window.open('http://user.lyck6.cn')
        }
    }).on('change', 'input', function() {
        setting[this.name] = this.value.match(/^\d+$/) ? parseInt(this.value) - 1 : -1;
        if (!this.value) setting[this.name] = this.name == 'num' ? 0 : undefined;
    }).detach(setting.hide ? '*' : 'html');
    setting.lose = setting.num = 0;
    if(url.match('exerciseList') || location.pathname.match('examexercise')){
        setting.loop = setInterval(ZhiHuiShuNewFindAnswer, setting.time * 2);
        setInterval(function() {
            $$(setting.queue.shift()).click();
        }, 1E3);
    }else if(location.hash.match(/dohomework|doexamination/)){
        setting.loop = setInterval(ZHSfindAnswer, setting.time);
        setInterval(function() {
            $$(setting.queue.shift()).parent().click();
        }, 1E3);
    }
}

function ZhiHuiShuNewFindAnswer(){
    if(setting.queue.length) return;
    var $TiMu = $$('.questionBox'),
        type = String(setting.type[$TiMu.find('.questionTit').text().match(/【(\S*)】/)[1]]);
    let postData = {
            question: filterImg($TiMu.find('.questionContent'),this).replace(/^（\S*）/,'').replace(/^【.*?】\s*/, '').replace(/\s*（\d+\.\d+分）$/, '').replace(/[(]\s*[)]。$/,'').replace(/（\s*）。$/,'').replace(/[(]\s*[)]$/,'').replace(/（\s*）$/,''),
            option: filterImg($TiMu.find('.optionUl'),this).replace(/\s+/,' ') || '',
            type: Boolean(type) ? type : 10
        }
    setting.num = parseInt($TiMu.find('.questionTit').text().match(/\d+/)[0]);
    GM_xmlhttpRequest({
        method: 'POST',
        url : 'http:/user.lyck6.cn/api/query/' + (userSetting.option ? (GM_getValue('phone') || setting.token || 'undefined') : '0'),
        headers: {
            'Content-type': 'application/x-www-form-urlencoded',
        },
        data: 'question=' + encodeURI(postData.question) + '&option='+ encodeURI(postData.option) + '&type='+ postData.type,
        timeout: setting.time,
        onload: function(xhr) {
            if (!setting.loop) {
            } else if (xhr.status == 200) {
                var obj = $$.parseJSON(xhr.responseText) || {};
                if (obj.code == 200) {
                    setting.div.children('div:eq(0)').text((!userSetting.option ? '正在搜索|答案不对加群反馈'+obj.data.qun : '正在搜索|当前积分剩余'+obj.data.num));
                    var answer = obj.data.answer.replace(/&/g, '&amp;').replace(/<([^i])/g, '&lt;$$1');
                    obj.data.answer = /^http/.test(answer) ? '<img src="' + obj.data.answer + '">' : obj.data.answer;
                    $$(
                        '<tr>' +
                        '<td style="text-align: center;">' + setting.num + '</td>' +
                        '<td title="点击可复制">' + (postData.question.match('<img') ? postData.question : postData.question.replace(/&/g, '&amp;').replace(/</g, '&lt')) + '</td>' +
                        '<td title="点击可复制">' + obj.data.answer + '</td>' +
                        '</tr>'
                    ).appendTo(setting.div.find('tbody')).css('background-color', ZhiHuiShuNewFillAnswer($TiMu.find('.optionUl').find('label'), obj, postData) ? '' : 'rgba(0, 150, 136, 0.6)');
                } else if (obj.code == 102 || obj.code == 305){
                    setting.div.children('div:eq(0)').data('html', obj.msg).siblings('button:eq(1)').click();
                    window.open('http://lyck6.cn/api/regist.php');
                } else if (obj.code == 110 || obj.code == 104){
                    setting.div.children('div:eq(0)').html(obj.msg);
                } else {
                    setting.div.children('div:eq(0)').html('出现未知异常，请联系QQ1666888816反馈该问题');
                }
            } else if (xhr.status == 403) {
                setting.div.children('div:eq(0)').data('html', '由于你的请求过于频繁，您的ip已被封<br>10分钟后自动解封<br>或者使用token答题不限制请求次数').siblings('button:eq(1)').click();
            } else if (xhr.status == 404) {
                setting.div.children('div:eq(0)').data('html', '最新版本已发布！请点击油猴按钮【用户脚本检测更新】完成更新。').siblings('button:eq(1)').click();
            }else {
                setting.div.children('div:eq(0)').text('发生未知异常，请联系QQ1666888816报告反馈bug');
            }
        },
        ontimeout: function() {
            setting.loop && setting.div.children('div:eq(0)').text('正在链接到云端，请稍后....<br>如果长时间链接不上请联系QQ1666888816');
        }
    });
}
function ZhiHuiShuNewFillAnswer($option,obj,postData){
    //真的是醉了，找个智慧树账号进行测试都这么难，目前只找到了  单选题/多选题/判断题   的题型
    //如果有热心的小伙伴可以提供智慧树账号给我测试QQ1666888816
    var str = String(obj.data.answer).toCDB(),
        data = str.split(/#|\x01|\|/),
        state = setting.lose;
    obj.data.success && $option.each(function(index){
        let tip = filterImg($$('.optionUl').find('label').eq(index).find('.optionContent'),this).toCDB()
        if (postData.type == 1){
            Boolean(($$.inArray(tip, data) + 1) || (str.indexOf(tip) + 1) || (tip.indexOf(str) + 1)) == Boolean($option.eq(index).attr('class').match('is-checked')) || setting.queue.push(this);
        } else if(postData.type == 3){
            console.log(111)
            tip = filterImg($$('.optionUl').find('label').eq(index).find('.el-radio__label'),this).toCDB()
            if (tip.match(/^(正确|是|对|√|T|ri)$/)) {
                data.join().match(/(^|,)(正确|是|对|√|T|ri)(,|$)/) && setting.queue.push(this)
            } else if (tip.match(/^(错误|否|错|×|F|wr)$$/)) {
                data.join().match(/(^|,)(错误|否|错|×|F|wr)(,|$)/) && setting.queue.push(this)
            }
        }else{
            Boolean($$.inArray(tip, data) + 1 || str.indexOf(tip) + 1 || tip.indexOf(str) + 1) && setting.queue.push(this);
        }
    })
    if (setting.queue.length) {
    } else if (/(0|1|3)/.test(postData.type)) {
        var $input = $option.find('input');
        $input.is(':checked') || (setting.none ? setting.queue.push($option.eq([Math.floor(Math.random() * $option.length)])) : setting.lose++);
    } else if (/^(2|4|5|9)$/.test(postData.type)) {

    } else {
        setting.none || setting.lose++;
    }
    setTimeout(function(){
        setting.jump && $$('.Topicswitchingbtn:contains(下一题)').click()
    },setting.time)

    if(setting.num == $$('.questionNumber-div').text().match(/\d+/)[0]) setting.div.children('div:eq(0)').data('html', '答题已完成').siblings('button:eq(1)').hide().click()
    return state == setting.lose ? true : reportProblem(postData);
}
function ZHSfindAnswer() {
    if (setting.queue.length) {
        return;
    } else if (!$$('.answerCard').length) {
        return setting.div.children('div:eq(0)').data('html', '非自动答题页面').siblings('button:eq(1)').click();
    } else if (setting.num >= $$('.subject_stem').length) {
        let tip = setting.lose ? '共有 <font color="red">' + setting.lose + '</font> 道题目待完善（已深色标注）' : '答题已完成';
        return setting.div.children('div:eq(0)').data('html', tip).siblings('button:eq(1), form').hide().click();
    } else if (!setting.curs.length) {
        setting.curs = $$('.infoList span').map(function() {
            return $$(this).text().trim();
        });
        if (!setting.curs.length) return;
    }
    var $$TiMu = $$('.subject_stem').eq(setting.num).parent(),
        type = $$TiMu.find('.subject_type').text().match(/【(.+)】|$/)[1],
        postData = {
            question: filterStyle($$TiMu.find('.subject_describe')),
            option: filterStyle($$('.examPaper_subject').eq(setting.num).find('.node_detail')).replace(/\s+/,' ') || '',
            type: type ? setting.type[type] : 10
        }
    GM_xmlhttpRequest({
        method: 'POST',
        url : 'http:/user.lyck6.cn/api/query/' + (userSetting.option ? (GM_getValue('phone') || setting.token || 'undefined') : '0'),
        headers: {
            'Content-type': 'application/x-www-form-urlencoded',
        },
        data: 'question=' + encodeURI(postData.question) + '&option='+ encodeURI(postData.option) + '&type='+ postData.type,
        timeout: setting.time,
        onload: function(xhr) {
            if (!setting.loop) {
            } else if (xhr.status == 200) {
                var obj = $$.parseJSON(xhr.responseText) || {};
                if (obj.code == 200) {
                    setting.div.children('div:eq(0)').text((!userSetting.option ? '正在搜索|答案不对加群反馈'+obj.data.qun : '正在搜索|当前积分剩余'+obj.data.num));
                    var answer = obj.data.answer.replace(/&/g, '&amp;').replace(/<([^i])/g, '&lt;$$1');
                    obj.data.answer = /^http/.test(answer) ? '<img src="' + obj.data.answer + '">' : obj.data.answer;
                    $$(
                        '<tr>' +
                            '<td style="text-align: center;">' + $$TiMu.find('.subject_num').text().trim().replace('.', '') + '</td>' +
                            '<td title="点击可复制">' + (postData.question.match('<img') ? postData.question : postData.question.replace(/&/g, '&amp;').replace(/</g, '&lt')) + '</td>' +
                            '<td title="点击可复制">' + obj.data.answer + '</td>' +
                        '</tr>'
                    ).appendTo(setting.div.find('tbody')).css('background-color', ZHSfillAnswer($$TiMu, obj, postData) ? '' : 'rgba(0, 150, 136, 0.6)');
                    setting.num++
                } else if (obj.code == 102 || obj.code == 305){
                    setting.div.children('div:eq(0)').data('html', obj.msg).siblings('button:eq(1)').click();
                    window.open('http://lyck6.cn/api/regist.php');
                } else if (obj.code == 110 || obj.code == 104){
                   setting.div.children('div:eq(0)').html(obj.msg);
                } else {
                    setting.div.children('div:eq(0)').html('出现未知异常，请联系QQ1666888816反馈该问题');
                }
            } else if (xhr.status == 403) {
                setting.div.children('div:eq(0)').data('html', '由于你的请求过于频繁，您的ip已被封<br>10分钟后自动解封<br>或者使用token答题不限制请求次数').siblings('button:eq(1)').click();
            } else if (xhr.status == 404) {
                setting.div.children('div:eq(0)').data('html', '最新版本已发布！请点击油猴按钮【用户脚本检测更新】完成更新。').siblings('button:eq(1)').click();
            }else {
                setting.div.children('div:eq(0)').text('发生未知异常，请联系QQ1666888816报告反馈bug');
            }
        },
        ontimeout: function() {
            setting.loop && setting.div.children('div:eq(0)').text('正在链接到云端，请稍后....<br>如果长时间链接不上请联系QQ1666888816');
        }
    });
}

function ZHSfillAnswer($$TiMu, obj, postData) {
    var $$div = $$TiMu.find('.nodeLab'),
    str = String(obj.data.answer).toCDB(),
    answer = str.split(/#|\x01|\|/),
    state = setting.lose;
    obj.data.success && $$div.each(function() {
        var $$input = $$('input', this)[0],
        tip = filterStyle('.node_detail', this).toCDB() || new Date().toString();
        if (tip.match(/^(正确|是|对|√|T|ri)$$/)) {
            answer.join().match(/(^|,)(正确|是|对|√|T|ri)(,|$)/) && setting.queue.push($$input);
        } else if (tip.match(/^(错误|否|错|×|F|wr)$$/)) {
            answer.join().match(/(^|,)(错误|否|错|×|F|wr)(,|$)/) && setting.queue.push($$input);
        } else if (postData.type == 1) {
            Boolean($$.inArray(tip, answer) + 1 || str.indexOf(tip) + 1) == $$input.checked || setting.queue.push($$input);
        } else {
            $$.inArray(tip, answer) + 1 && setting.queue.push($$input);
        }
    });
    if (setting.queue.length) {
    } else if (/^(0|1|3)$/.test(postData.type)) {
        var $$input = $$div.find('input');
        $$input.is(':checked') || (setting.none ? setting.queue.push($$input[Math.floor(Math.random() * $$input.length)]) : setting.lose++);
    } else if (/^(2|4|5|9)$/.test(postData.type)) {
        answer = String(obj.data.answer).split(/#|\x01|\|/);
        str = $$TiMu.find('textarea').each(function(index) {
            index = (obj.data.success && answer[index]) || '';
            this.value = index.trim();
            this.dispatchEvent(new Event('input'));
            this.dispatchEvent(new Event('blur'));
        }).length;
        (obj.data.success && answer.length == str) || setting.none || setting.lose++;
    } else {
        setting.none || setting.lose++;
    }
    return state == setting.lose ? true : reportProblem(postData);
}

function hookHiexam() {
    var ajax = new xhr();
    ajax.onload = function() {
        if (this.status != 200 || !this.responseURL.match('getDoQuestSingle')) return;
        var obj = JSON.parse(this.responseText).rt;
        $$.each(obj.questionOptionList || [], function(index) {
            var $$input = $$('.TitleOptions-div input')[index];
            if (obj.questionTypeId == 1) {
                this.isCorrect && setting.queue.push($$input);
            } else if (obj.questionTypeId == 2) {
                this.isCorrect == $$input.checked || setting.queue.push($$input);
            }
        });
    };
    return ajax;
}

function filterStyle(dom, that) {
    var $$dom = $$(dom, that).clone().find('style').remove().end();
    return $$dom.find('img[src]').replaceWith(function() {
        return $$('<p></p>').text('<img src="' + $$(this).attr('src') + '">');
    }).end().text().trim();
}

function ExamFillAnswer(obj, postData) {
    let tip;
    var $$input = $$(':radio, :checkbox', '.Cy_ulBottom'),
        flag = false,
        str = String(obj.data.answer).toCDB(),
        data = str.split(/#|\x01|\|/),
        btn = $$('.saveYl:contains(下一题)').offset();
    obj.data.success && $$input.each(function(index) {
        if (this.value == 'true') {
            if(data.join().match(/(^|,)(正确|是|对|√|T|ri)(,|$)/)){
                this.click();
                flag = true;
            }
        } else if (this.value == 'false') {
            if(data.join().match(/(^|,)(错误|否|错|×|F|wr)(,|$)/)){
                this.click();
                flag = true;
            }
        } else {
            index = postData.$li[index].toCDB()
            index = $$.inArray(index, data) + 1 || (postData.type == 1 && str.indexOf(index) + 1);
            if(Boolean(index)) flag = true;
            Boolean(index) == this.checked || this.click();
        }
    }).each(function() {
        if (!/^A?B?C?D?E?F?G?$/.test(str)) return false;
        if(str.match(this.value)) flag = true;
        Boolean(str.match(this.value)) == this.checked || this.click();
    });
    if (postData.type.match(/^[013]$/)) {
        tip = $$input.is(':checked') || setting.none && (($$input[Math.floor(Math.random() * $$input.length)] || $$()).click(), ' ');
    } else if (postData.type.match(/^(2|[4-9]|1[08])$/)) {
        data = String(obj.data.answer).split(/#|\x01|\|/);
        tip = $$('.Cy_ulTk textarea').each(function(index) {
            index = (obj.code == 200 && data[index]) || '';
            obj.data.success ? UE.getEditor(this.name).setContent(index.trim()) : ''
        }).length;
        tip = (obj.data.success && data.length == tip) || setting.none && ' ';
        setting.len = str.length * setting.time / 10;
    }
    if (tip == ' ') {
        tip = '已执行默认操作';
    } else if (tip) {
        flag = true;
        tip = '自动答题已完成';
    } else if (tip === undefined) {
        tip = '该题型不支持自动答题';
    } else {
        tip = '未找到有效答案';
    }
    if (btn) {
        tip += setting.jump ? '，即将切换下一题' : '，未开启自动切换';
        setInterval(function() {
            if (!setting.jump) return;
            var mouse = document.createEvent('MouseEvents'),
            arr = [btn.left + Math.ceil(Math.random() * 80), btn.top + Math.ceil(Math.random() * 26)];
            mouse.initMouseEvent('click', true, true, document.defaultView, 0, 0, 0, arr[0], arr[1], false, false, false, false, 0, null);
            _self.event = $$.extend(true, {}, mouse);
            delete _self.event.isTrusted;
            _self.getTheNextQuestion(1);
        }, setting.len || Math.ceil(setting.time * Math.random()) * 2);
    } else {
        setting.$$btn.eq(1).hide();
        tip = '答题已完成，请自行查看答题详情';
    }
    setting.$$div.data('html', tip).siblings('button:eq(1)').hide().click();
    return flag ? true : reportProblem(postData);
}

function ExamFindTiMu() {
    let postData = {
        question: filterImg('.Cy_TItle .clearfix').replace(/\s*（\d+\.\d+分）$/, ''),
        option: filterImg('.Cy_ulTop').replace(/、/g,'').replace(/\s+/g,' '),
        type: $$('[name^=type]:not([id])').val() || '10',
        $li: Array.prototype.slice.call($$('li .clearfix').map(function() {
            return filterImg(this);
        }))
    }
    GM_xmlhttpRequest({
        method: 'POST',
        url : 'http:/user.lyck6.cn/api/query/' + (userSetting.option ? (GM_getValue('phone') || setting.token || 'undefined') : '0'),
        headers: {
            'Content-type': 'application/x-www-form-urlencoded',
        },
        data: 'question=' + encodeURI(postData.question) + '&option=' + encodeURI(postData.option) + '&type=' + postData.type,
        timeout: setting.time,
        onload: function(xhr) {
            if (!setting.loop) {
            } else if (xhr.status == 200) {
                var obj = $$.parseJSON(xhr.responseText) || {};
                if (obj.code == 200) {
                    var answer = String(obj.data.answer).replace(/&/g, '&amp;').replace(/<(?!img)/g, '&lt;'),
                    que = postData.question.match('<img') ? postData.question : postData.question.replace(/&/g, '&amp;').replace(/</g, '&lt');
                    obj.data.answer = /^http/.test(answer) ? '<img src="' + obj.data.answer + '">' : obj.data.answer;
                    $$(
                        '<tr>' +
                            '<td title="点击可复制">' + que + '</td>' +
                            '<td title="点击可复制">' + obj.data.answer + '</td>' +
                           '<td title="积分剩余">' +obj.data.num + '</td>' +
                        '</tr>'
                    ).appendTo(setting.div.find('tbody')).css('background-color',ExamFillAnswer(obj,postData) ? '' : 'rgba(0, 150, 136, 0.6)');
                } else if (obj.code == 102 || obj.code == 305){
                    window.open('http://lyck6.cn/api/regist.php')
                    setting.$$div.data('html', obj.message).siblings('button:eq(1)').click();
                }else if(obj.code == 110 || obj.code == 104){
                    setting.$$div.html(obj.msg);
                }else{
                    setting.$$div.html('出现未知异常，请联系QQ1666888816');
                }
            } else if (xhr.status == 403) {
                setting.$$div.data('html', '由于你的请求过于频繁，您的ip已被封<br>10分钟后自动解封<br>或者使用token答题不限制请求次数').siblings('button:eq(1)').click();
            } else if (xhr.status == 404) {
                setting.$$div.data('html', '最新版本已发布！请点击油猴按钮【用户脚本检测更新】完成更新。').siblings('button:eq(1)').click();
            } else {
                 setting.$$div.html('出现未知异常，请联系QQ1666888816');
            }
        },
        ontimeout: function() {
            setting.loop && setting.$$div.html('正在链接到云端，请稍后....<br>如果长时间链接不上请联系QQ1666888816');
        }
    });
}

function Exam(){
    setting.div = $$(
        '<div id = "setting" style="border: 2px dashed rgb(0, 85, 68); width: 330px; position: fixed; top: 0; right: 0; z-index: 99999; background-color: #FF7F00; overflow-x: auto;">' +
            '<span style="font-size: medium;"></span>' +
            '<img src="http://lyck6.cn/img/6.png" width="100%" />'+
            '设置token(手机号):<input id="phonenum" type="text name="token" value='+GM_getValue('phone')+'>'+
            '<button id="button" type="submit">确定</button>'+
            '<div style="color: bule;background: #B0E2FF;;font-size: 15px;margin-bottom: 1%;">目前默认搜索|'+(userSetting.option ? 'token题库':'免费题库')+'<br>更改默认设置请修改脚本参数option<br>临时更改点击下方按钮</div>' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 60px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">暂停答题</button> ' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 110px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;' + (setting.jump ? '' : ' display: none;') + '">点击停止本次切换</button>' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 60px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">重新查询</button> ' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 60px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">答题详情</button> ' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 110px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">' + (userSetting.option ? '取消请求token题库' : '开启请求token题库') + '</button>' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 70px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">获取积分</button>' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 70px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">手动注册</button>' +
           '<button  style="background-color:  #4CAF50;border: none;margin: 1%;color: white;width: 70px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">拓展功能</button>' +
            '<div style="max-height: 200px; overflow-y: auto;">' +
                '<table border="1" style="font-size: 12px;">' +
                    '<thead>' +
                        '<tr>' +
                            '<th colspan="2">' + ($$('#randomOptions').val() == 'false' ? '' : '<font color="red">本次考试的选项为乱序 脚本会选择正确的选项</font>') + '</th>' +
                        '</tr>' +
                        '<tr>' +
                            '<th style="width: 60%; min-width: 130px;">题目（点击可复制）</th>' +
                            '<th style="min-width: 130px;">答案（点击可复制）</th>' +
                           '<th style="min-width: 130px;">积分明细（剩余）</th>' +
                        '</tr>' +
                    '</thead>' +
                    '<tfoot style="' + (setting.jump ? ' display: none;' : '') + '">' +
                        '<tr>' +
                            '<th colspan="2">已关闭 本次自动切换</th>' +
                        '</tr>' +
                    '</tfoot>' +
                    '<tbody>' +
                        '<tr>' +
                            '<td colspan="2" style="display: none;"></td>' +
                        '</tr>' +
                    '</tbody>' +
                '</table>' +
            '</div>' +
        '</div>'
    ).appendTo('body').on('click', 'button, td', function() {
        var num = setting.$$btn.index(this);
        if (num == -1) {
            GM_setClipboard($$(this).text());
        } else if (num === 0){
            GM_setValue('phone',document.getElementById('phonenum').value)
        } else if (num === 1) {
            if (setting.loop) {
                clearInterval(setting.loop);
                delete setting.loop;
                num = ['已暂停搜索'+(userSetting.option ? 'token题库':'免费题库'), '继续答题'];
            } else {
                setting.loop = setInterval(ExamFindTiMu, setting.time);
                num = ['正在搜索'+(+userSetting.option ? 'token题库':'免费题库') ,'暂停答题'];
            }
            setting.$$div.html(function() {
                return $$(this).data('html') || num[0];
            }).removeData('html');
            $$(this).html(num[1]);
        } else if (num == 2) {
            setting.jump = 0;
            setting.$$div.html(function() {
                return arguments[1].replace('即将切换下一题', '未开启自动切换');
            });
            setting.div.find('tfoot').add(this).toggle();
        } else if (num == 3) {
            location.reload();
        } else if (num == 5) {
            userSetting.option = !userSetting.option;
            $$(this).html(userSetting.option ? '取消请求token题库' : '开启请求token题库');
            GM_setValue('userSetting',userSetting)
        } else if (num == 4) {
            ($$('.leftCard .saveYl')[0] || $$()).click();
        } else if (num == 6) {
            window.open("http://lyck6.cn/pay/index.php?&phone="+ GM_getValue('phone'));
        } else if (num == 7){
           window.open('http://lyck6.cn/api/regist.php?phone='+ GM_getValue('phone'))
        } else if (num == 8){
           window.open('http://user.lyck6.cn')
        }
    }).detach(setting.hide ? '*' : 'html');
    setting.$$btn = setting.div.children('button');
    setting.$$div = setting.div.children('div:eq(0)');
    if (setting.scale) _self.UEDITOR_CONFIG.scaleEnabled = false;
    $$.each(UE.instants, function() {
        var key = this.key;
        this.ready(function() {
            this.destroy();
            UE.getEditor(key);
        });
    });
    setting.loop = setInterval(ExamFindTiMu, setting.time);
}

function ZhiJiaoYunBeforeFind() {
    setting.div = $$(
       '<div style="box-shadow: darkgrey 10px 10px 10px 5px;border: 0.5px solid #666;width: 330px;background-color: #FF7F00; position: fixed; top: 100px; right: 300px; z-index: 99999;">' +
       '<span style="font-size: medium;"></span>' +
       '<img src="http://lyck6.cn/img/6.png" width="100%" />'+
        '设置token(手机号):<input id="phone" type="text name="token" value='+ GM_getValue('phone') + '>'+
        '<button id="button" type="submit">确定</button>'+
        '<div style="color: bule;background: #B0E2FF;;font-size: 15px;margin-bottom: 1%;">目前默认搜索|'+(userSetting.option ? 'token题库':'免费题库')+'<br>更改默认设置请修改脚本参数option<br>临时更改点击下方按钮</div>' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 60px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">暂停答题</button> ' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 110px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">' + (setting.auto ? '取消本次自动提交' : '开启本次自动提交') + '</button>' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 110px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">' + (userSetting.option ? '取消请求token题库' : '开启请求token题库') + '</button>' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 60px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">重新查询</button>' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 60px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">折叠面板</button>' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 70px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">获取积分</button>' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 70px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">手动注册</button>' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 70px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">拓展功能</button>' +
        '<div style="max-height: 300px; overflow-y: auto;">' +
                '<table border="1"  style="font-size: 12px;color:black;background-color:#FF7F00;">' +
                    '<thead>' +
                        '<tr>' +
                            '<th style="width: 25px; min-width: 25px;">题号</th>' +
                            '<th style="width: 60%; min-width: 130px;">题目（点击可复制）</th>' +
                            '<th style="min-width: 130px;">答案（点击可复制）</th>' +
                        '</tr>' +
                    '</thead>' +
                    '<tfoot style="display: none;">' +
                        '<tr>' +
                            '<th colspan="3">答案提示框 已折叠</th>' +
                        '</tr>' +
                    '</tfoot>' +
                    '<tbody style="overflow-y: scroll;80px;">'+
                        '<tr>' +

                        '</tr>' +
                    '</tbody>' +
                '</table>' +
            '</div>' +
        '</div>'
    ).appendTo('body').on('click', 'button, td', function() {
        var len = $$(this).prevAll('button').length;
        if (this.nodeName == 'TD') {
            $$(this).prev().length && GM_setClipboard($$(this).text());
        } else if (!$$(this).siblings().length) {
            $$(this).parent().text('正在搜索|防止失联建议加群1102188986');
            setting.num++;
        } else if (len === 0){
            GM_setValue('phone',$$("#phone").val())
        }else if (len === 1) {
            if (setting.loop) {
                clearInterval(setting.loop);
                delete setting.loop;
                len = ['已暂停搜索'+(+userSetting.option ? 'token题库':'免费题库'), '继续答题'];
            } else {
                if(location.pathname == '/study/directory/dir_course.html' || location.pathname == '/study/works/works.html'){
                    setting.loop = setInterval(GreenZhiJiaoYunFindAnswer, setting.time);
                }else{
                    setting.loop = setInterval(ZhiJiaoYunFindAnswer, setting.time);
                }
                len = ['正在搜索'+(+userSetting.option ? 'token题库':'免费题库'), '暂停答题'];
            }
            setting.div.children('div:eq(0)').html(function() {
                return $$(this).data('html') || len[0];
            }).removeData('html');
            $$(this).html(len[1]);
        } else if (len == 2) {
            setting.auto = !setting.auto;
            $$(this).html(setting.auto ? '取消本次自动提交' : '开启本次自动提交');
        } else if (len == 3) {
             userSetting.option = !userSetting.option;
            $$(this).html(userSetting.option ? '取消请求token题库' : '开启请求token题库');
            GM_setValue('userSetting',userSetting)
        } else if (len == 4) {
             parent.location.reload();
        }else if (len == 5) {
            setting.div.find('tbody, tfoot').toggle();
        }else if (len == 6) {
            window.open("http://lyck6.cn/pay/index.php?&phone="+ GM_getValue('phone'));
        } else if (len == 7){
           window.open('http://lyck6.cn/api/regist.php?phone='+ GM_getValue('phone')+'&uid='+ getInfo())
        } else if (len == 8){
           window.open('http://user.lyck6.cn')
        }
    }).find('table, td, th').css('border', '1px solid').end().detach(setting.hide ? '*' : 'html');
    setting.lose = setting.num = 0;
    setting.over = '<button style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 80px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 16px;">跳过此题</button>';
    if(location.pathname == '/study/directory/dir_course.html' || location.pathname == '/study/works/works.html'){
        setting.loop = setInterval(GreenZhiJiaoYunFindAnswer, setting.time);
    }else{
        setting.loop = setInterval(ZhiJiaoYunFindAnswer, setting.time);
    }
    setInterval(function() {$$(setting.queue.shift()).click();}, 1E3);
}
function ZhiJiaoYunFindAnswer(){
    var $TiMu = $('.center-all');
    let postData = {
        question: filterImg($TiMu.find('.e-q-body').eq(setting.num).find('.e-q-quest').find('.e-q-q').eq(0)).replace(/\s+/g,' '),
        option: filterImg($TiMu.find('.e-a-g').eq(setting.num),this).replace(/\s+/g,' '),
        type: setting.type[$TiMu.find('.quiz-type').eq(setting.num).text().replace(/\s+/g,'')]
    }
    if(setting.num >= $TiMu.find('.e-q-body').length){
        let tip = setting.lose ? '共有 <font color="red">' + setting.lose + '</font> 道题目待完善（已深色标注）' : '答题已完成';
        return setting.div.children('div:eq(0)').data('html', tip).siblings('button:eq(1), form').hide().click();
    }
    GM_xmlhttpRequest({
        method: 'POST',
        url : 'http:/user.lyck6.cn/api/query/' + (userSetting.option ? (GM_getValue('phone') || setting.token || 'undefined') : '0'),
        headers: {
            'Content-type': 'application/x-www-form-urlencoded',
        },
        data: 'question=' + encodeURI(postData.question) + '&option='+ encodeURI(postData.option) + '&type=' + postData.type,
        timeout: setting.time,
        onload: function(xhr) {
            if (!setting.loop) {
            } else if (xhr.status == 200) {
                var obj = $$.parseJSON(xhr.responseText) || {};
                if (obj.code == 200) {
                    userSetting.option ? setting.div.children('div:eq(0)').text('正在搜索token题库--当前积分剩余：'+obj.data.num):setting.div.children('div:eq(0)').text('正在搜索免费题库|防止失联建议加群'+obj.data.qun);
                    var td = '<td style="border: 1px solid" colspan="1" font-size: 1.1em;text-align: left;',
                    answer = String(obj.data.answer).replace(/&/g, '&amp;').replace(/<(?!img)/g, '&lt;');
                    obj.data.answer = /^http/.test(answer) ? '<img src="' + obj.data.answer + '">' : obj.data.answer;
                    $$(
                        '<tr>' +
                            td + ' text-align: center;">' + (parseInt(setting.num) + 1) + '</td>' +
                            td + '" title="点击可复制">' + (postData.question.match('<img') ? postData.question : postData.question.replace(/&/g, '&amp;').replace(/</g, '&lt')) + '</td>' +
                            td + '" title="点击可复制">' + obj.data.answer +'</td>' +
                        '</tr>'
                    ).appendTo(setting.div.find('tbody')).css('background-color',ZhiJiaoYunFillAnswer($TiMu.find('.e-q-body').eq(setting.num).find('.e-a'), obj, postData) ? '' : 'rgba(0, 150, 136, 0.6)');
                   setting.num++;
                } else if(obj.code == 110 || obj.code == 104){
                    setting.div.children('div:eq(0)').html(obj.msg);
                } else if (obj.code == 102 || obj.code == 305){
                    setting.div.children('div:eq(0)').data('html', obj.msg).siblings('button:eq(1)').click();
                    window.open('http://lyck6.cn/api/regist.php')
                } else{
                    setting.div.children('div:eq(0)').html('发现未知异常，请联系QQ1666888816报告反馈bug').siblings('button:eq(1)').click();;
                }
                //setting.div.children('span').html(obj.msg || '');
            } else if (xhr.status == 403) {
                setting.div.children('div:eq(0)').data('html', '由于你的请求过于频繁，您的ip已被封<br>10分钟后自动解封<br>或者使用token答题不限制请求次数').siblings('button:eq(1)').click();
            } else if (xhr.status == 404) {
                setting.div.children('div:eq(0)').data('html', '最新版已发布！请点击油猴按钮【用户脚本检查更新】完成更新！').siblings('button:eq(1)').click();
            }else {
                setting.div.children('div:eq(0)').html('发现未知异常，请联系QQ1666888816处理');
            }
        },
        ontimeout: function() {
            setting.loop && setting.div.children('div:eq(0)').html(setting.over + '正在链接到云端，请稍后....<br>如果长时间链接不上请联系QQ1666888816');
        }
    });
}

function ZhiJiaoYunFillAnswer($option,obj ,postData){
     var str = String(obj.data.answer).toCDB(),
        data = str.split(/#|\x01|\|/),
        state = setting.lose,
        flag = false;
    obj.code == 200 && $option.each(function() {
        let tip = String(filterImg($(this).find('div'))).toCDB();
        if (postData.type == 3 && String(filterImg($(this))).toCDB().match(/(正确|是|对|√|T|ri)$/)) {
            data.join().match(/(^|,)(正确|是|对|√|T|ri)(,|$)/) && setting.queue.push(this);
        } else if (postData.type == 3 && String(filterImg($(this))).toCDB().match(/(错误|否|错|×|F|wr)$/)) {
            data.join().match(/(^|,)(错误|否|错|×|F|wr)(,|$)/) && setting.queue.push(this);
        } else if (postData.type == 1) {
            Boolean($$.inArray(tip, data) + 1 || str.indexOf(tip) + 1) == Boolean($$(this).attr('class').match('checked')) || setting.queue.push(this);
        } else {
            $$.inArray(tip, data) + 1 && setting.queue.push(this);
        }
    });
    if (setting.queue.length) {
    } else if (/^(0|1|3)$/.test(postData.type)) {
        Boolean($$('.center-all').find('.e-q-body').find('form').eq(setting.num).find("input[name='answer']").val()) || (setting.none ? setting.queue.push($option[Math.floor(Math.random() * $option.length)]) : setting.lose++);
    } else if (/^(2)$/.test(postData.type)) {
        //暂时没有人提供其他类型的题目
    } else {
        setting.none || setting.lose++;
    }
    return state == setting.lose ? true : reportProblem(postData);
}

function reportProblem(data){
    GM_xmlhttpRequest({
        method: 'POST',
        url: 'http://user.lyck6.cn/api/report' ,
        headers: {
            'Content-type': 'application/x-www-form-urlencoded'
        },
        data: 'data=' + encodeURI(JSON.stringify(data))
    });
    return false;
}
function getGreenZhiJiaoYunData(){
    var $TiMu = $('#container');
    var data = $TiMu.find('.preview_item').map(function(){
        return {
            question: filterImg($(this).find('.preview_cm').find('div:first')).replace(/\s+/,' '),
            course: '青版智慧职教'
        }
    })
    var typelist = []
    $TiMu.find('.panel_title').each(function(){
        var title = filterImg(this)
        let type = title.match(/(\S*)题/)[0];
        let Tnum = title.match(/共(\d+)题/)[1];
        for (let i =0;i<Tnum;i++){
            typelist.push(type)
        }
    })
    for(let index = 0;index<data.length;index++){
        data[index].type = setting.type[typelist[index]]
    }
    data = $.grep(data.map(function(index){
        if(this.type == 0 || this.type == 1){
            this.option = Array.prototype.slice.call($TiMu.find('.preview_choices').eq(index).find('li').map(function(){
                return {
                    key: filterImg(this).match(/[A-G]/)[0],
                    option: filterImg($(this).find('.preview_cont:last')).replace(/\s+/,' ')
                }
            }))
        }
        return this
    }),function(value){return value})
    return data;
}

function GreenZhiJiaoYunFindAnswer(){
   let data = getGreenZhiJiaoYunData();
    if(setting.num >= data.length){
        let tip = setting.lose ? '共有 <font color="red">' + setting.lose + '</font> 道题目待完善（已深色标注）<br>刷新页面此脚本搜索框会自动消失' : '答题已完成<br>刷新页面此脚本搜索框会自动消失';
        return setting.div.children('div:eq(0)').data('html', tip).siblings('button:eq(1), form').hide().click();
    }
    let postData = data[setting.num];
    GM_xmlhttpRequest({
        method: 'POST',
        url : 'http:/user.lyck6.cn/api/query/' + (userSetting.option ? (GM_getValue('phone') || setting.token || 'undefined') : '0'),
        headers: {
            'Content-type': 'application/x-www-form-urlencoded',
        },
        data: 'question=' + encodeURI(postData.question) + '&option='+ encodeURI(JSON.stringify(postData.option) || '') + '&type=' + postData.type,
        timeout: setting.time,
        onload: function(xhr) {
            if (!setting.loop) {
            } else if (xhr.status == 200) {
                var obj = $$.parseJSON(xhr.responseText) || {};
                if (obj.code == 200) {
                    userSetting.option ? setting.div.children('div:eq(0)').text('正在搜索token题库--当前积分剩余：'+obj.data.num):setting.div.children('div:eq(0)').text('正在搜索免费题库|防止失联建议加群'+obj.data.qun);
                    var td = '<td style="border: 1px solid" colspan="1" font-size: 1.1em;text-align: left;',
                    answer = String(obj.data.answer).replace(/&/g, '&amp;').replace(/<(?!img)/g, '&lt;');
                    obj.data.answer = /^http/.test(answer) ? '<img src="' + obj.data.answer + '">' : obj.data.answer;
                    $$(
                        '<tr>' +
                            td + ' text-align: center;">' + (parseInt(setting.num) + 1) + '</td>' +
                            td + '" title="点击可复制">' + (postData.question.match('<img') ? postData.question : postData.question.replace(/&/g, '&amp;').replace(/</g, '&lt')) + '</td>' +
                            td + '" title="点击可复制">' + obj.data.answer +'</td>' +
                        '</tr>'
                    ).appendTo(setting.div.find('tbody')).css('background-color',GreenZhiJiaoYunFillAnswer($('#container').find('.preview_choices').eq(setting.num).find('li'), obj, postData) ? '' : 'rgba(0, 150, 136, 0.6)');
                   setting.num++;
                } else if(obj.code == 110 || obj.code == 104){
                    setting.div.children('div:eq(0)').html(obj.msg);
                } else if (obj.code == 102 || obj.code == 305){
                    setting.div.children('div:eq(0)').data('html', obj.msg).siblings('button:eq(1)').click();
                    window.open('http://lyck6.cn/api/regist.php')
                } else{
                    setting.div.children('div:eq(0)').html('发现未知异常，请联系QQ1666888816报告反馈bug').siblings('button:eq(1)').click();;
                }
                //setting.div.children('span').html(obj.msg || '');
            } else if (xhr.status == 403) {
                setting.div.children('div:eq(0)').data('html', '由于你的请求过于频繁，您的ip已被封<br>10分钟后自动解封<br>或者使用token答题不限制请求次数').siblings('button:eq(1)').click();
            } else if (xhr.status == 404) {
                setting.div.children('div:eq(0)').data('html', '最新版已发布！请点击油猴按钮【用户脚本检查更新】完成更新！').siblings('button:eq(1)').click();
            }else {
                setting.div.children('div:eq(0)').html('发现未知异常，请联系QQ1666888816处理');
            }
        },
        ontimeout: function() {
            setting.loop && setting.div.children('div:eq(0)').html(setting.over + '正在链接到云端，请稍后....<br>如果长时间链接不上请联系QQ1666888816');
        }
    });
}

function GreenZhiJiaoYunFillAnswer($option,obj ,postData){
     var str = String(obj.data.answer).toCDB(),
        data = str.split(/#|\x01|\|/),
        state = setting.lose,
        flag = false;
    obj.data.success && $option.each(function() {
        let tip = String(filterImg($(this).find('.preview_cont:last'))).toCDB();
        if (postData.type == 3 && String(filterImg($(this))).toCDB().match(/(正确|是|对|√|T|ri)$/)) {
            data.join().match(/(^|,)(正确|是|对|√|T|ri)(,|$)/) && setting.queue.push($(this).find('span').eq(0).find('input'));
        } else if (postData.type == 3 && String(filterImg($(this))).toCDB().match(/(错误|否|错|×|F|wr)$/)) {
            data.join().match(/(^|,)(错误|否|错|×|F|wr)(,|$)/) && setting.queue.push($(this).find('span').eq(0).find('input'));
        } else if (postData.type == 1) {
            Boolean($$.inArray(tip, data) + 1 || str.indexOf(tip) + 1) == Boolean($$(this).find('.preview_cont:first').find('input').attr('checked')) || setting.queue.push($(this).find('span').eq(0).find('input'));
        } else {
            $$.inArray(tip, data) + 1 && setting.queue.push($(this).find('span').eq(0).find('input'));
        }
    });
    if (setting.queue.length) {
    } else if (/^(0|1|3)$/.test(postData.type)) {
        $$(this).find('.preview_cont:first').find('input').attr('checked') || (setting.none ? setting.queue.push($option.eq([Math.floor(Math.random() * $option.length)]).find('span').eq(0).find('input')) : setting.lose++);
    } else if (/^(2)$/.test(postData.type)) {
        //暂时没有人提供其他类型的题目
    } else {
        setting.none || setting.lose++;
    }
    return state == setting.lose ? true : reportProblem(postData);
}

function YiBinBeforeFind() {
    setting.div = $$(
       '<div style="box-shadow: darkgrey 10px 10px 10px 5px;border: 0.5px solid #666;width: 330px;background-color: #FF7F00; position: fixed; top: 100px; right: 300px; z-index: 99999;">' +
       '<span style="font-size: medium;"></span>' +
       '<img src="http://lyck6.cn/img/6.png" width="100%" />'+
        '设置token(手机号):<input id="phone" type="text name="token" value='+ GM_getValue('phone') + '>'+
        '<button id="button" type="submit">确定</button>'+
        '<div style="color: bule;background: #B0E2FF;;font-size: 15px;margin-bottom: 1%;">目前默认搜索|'+(userSetting.option ? 'token题库':'免费题库')+'<br>更改默认设置请修改脚本参数option<br>临时更改点击下方按钮</div>' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 60px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">暂停答题</button> ' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 110px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">' + (setting.auto ? '取消本次自动提交' : '开启本次自动提交') + '</button>' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 110px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">' + (userSetting.option ? '取消请求token题库' : '开启请求token题库') + '</button>' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 60px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">重新查询</button>' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 60px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">折叠面板</button>' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 70px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">获取积分</button>' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 70px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">手动注册</button>' +
            '<button  style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 70px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 10px;">拓展功能</button>' +
        '<div style="max-height: 300px; overflow-y: auto;">' +
                '<table border="1"  style="font-size: 12px;color:black;background-color:#FF7F00;">' +
                    '<thead>' +
                        '<tr>' +
                            '<th style="width: 25px; min-width: 25px;">题号</th>' +
                            '<th style="width: 60%; min-width: 130px;">题目（点击可复制）</th>' +
                            '<th style="min-width: 130px;">答案（点击可复制）</th>' +
                        '</tr>' +
                    '</thead>' +
                    '<tfoot style="display: none;">' +
                        '<tr>' +
                            '<th colspan="3">答案提示框 已折叠</th>' +
                        '</tr>' +
                    '</tfoot>' +
                    '<tbody style="overflow-y: scroll;80px;">'+
                        '<tr>' +

                        '</tr>' +
                    '</tbody>' +
                '</table>' +
            '</div>' +
        '</div>'
    ).appendTo('body').on('click', 'button, td', function() {
        var len = $$(this).prevAll('button').length;
        if (this.nodeName == 'TD') {
            $$(this).prev().length && GM_setClipboard($$(this).text());
        } else if (!$$(this).siblings().length) {
            $$(this).parent().text('正在搜索|防止失联建议加群1102188986');
            setting.num++;
        } else if (len === 0){
            GM_setValue('phone',$$("#phone").val())
        }else if (len === 1) {
            if (setting.loop) {
                clearInterval(setting.loop);
                delete setting.loop;
                len = ['已暂停搜索'+(+userSetting.option ? 'token题库':'免费题库'), '继续答题'];
            } else {
                setting.loop = setInterval(YiBinFindAnswer, setting.time);
                len = ['正在搜索'+(+userSetting.option ? 'token题库':'免费题库'), '暂停答题'];
            }
            setting.div.children('div:eq(0)').html(function() {
                return $$(this).data('html') || len[0];
            }).removeData('html');
            $$(this).html(len[1]);
        } else if (len == 2) {
            setting.auto = !setting.auto;
            $$(this).html(setting.auto ? '取消本次自动提交' : '开启本次自动提交');
        } else if (len == 3) {
             userSetting.option = !userSetting.option;
            $$(this).html(userSetting.option ? '取消请求token题库' : '开启请求token题库');
            GM_setValue('userSetting',userSetting)
        } else if (len == 4) {
             parent.location.reload();
        }else if (len == 5) {
            setting.div.find('tbody, tfoot').toggle();
        }else if (len == 6) {
            window.open("http://lyck6.cn/pay/index.php?&phone="+ GM_getValue('phone'));
        } else if (len == 7){
           window.open('http://lyck6.cn/api/regist.php?phone='+ GM_getValue('phone')+'&uid='+ getInfo())
        } else if (len == 8){
           window.open('http://user.lyck6.cn')
        }
    }).find('table, td, th').css('border', '1px solid').end().detach(setting.hide ? '*' : 'html');
    setting.lose = setting.num = 0;
    setting.over = '<button style="background-color: #4CAF50;border: none;margin: 1%;color: white;width: 80px;height: 30px;text-align: center;text-decoration: none;display: inline-block;font-size: 16px;">跳过此题</button>';
    setting.loop = setInterval(YiBinFindAnswer, setting.time);
    setInterval(function() {$$(setting.queue.shift()).find('span:first').find('a').click();}, 1E3);
}

function YiBinFindAnswer(){
    var $TiMu = $('.view-test').eq(setting.num);
    var typeText = $TiMu.find('.test-header').text().trim().match(/^\[(\S*)\]/);
    if(setting.num >= $('.test-text-tutami').length){
        let tip = setting.lose ? '共有 <font color="red">' + setting.lose + '</font> 道题目待完善（已深色标注）<br>刷新页面此脚本搜索框会自动消失' : '答题已完成<br>刷新页面此脚本搜索框会自动消失';
        return setting.div.children('div:eq(0)').data('html', tip).siblings('button:eq(1), form').hide().click();
    }
    let postData = {
        question: filterImg($TiMu.find('.test-text-tutami'),this),
        option: filterImg($TiMu.find('.test-options'),this),
        type: typeText ? setting.type[typeText[1]] : 10
    }
    console.log(parseInt(setting.num))
    if($('.main').find('.practice-no').find('a').eq(parseInt(setting.num)).click())console.log(1111111111111111)
    GM_xmlhttpRequest({
        method: 'POST',
        url : 'http:/user.lyck6.cn/api/query/' + (userSetting.option ? (GM_getValue('phone') || setting.token || 'undefined') : '0'),
        headers: {
            'Content-type': 'application/x-www-form-urlencoded',
        },
        data: 'question=' + encodeURI(postData.question) + '&option='+ encodeURI(JSON.stringify(postData.option) || '') + '&type=' + postData.type,
        timeout: setting.time,
        onload: function(xhr) {
            if (!setting.loop) {
            } else if (xhr.status == 200) {
                var obj = $$.parseJSON(xhr.responseText) || {};
                if (obj.code == 200) {
                    userSetting.option ? setting.div.children('div:eq(0)').text('正在搜索token题库--当前积分剩余：'+obj.data.num):setting.div.children('div:eq(0)').text('正在搜索免费题库|防止失联建议加群'+obj.data.qun);
                    var td = '<td style="border: 1px solid" colspan="1" font-size: 1.1em;text-align: left;',
                    answer = String(obj.data.answer).replace(/&/g, '&amp;').replace(/<(?!img)/g, '&lt;');
                    obj.data.answer = /^http/.test(answer) ? '<img src="' + obj.data.answer + '">' : obj.data.answer;
                    $$(
                        '<tr>' +
                            td + ' text-align: center;">' + (parseInt(setting.num) + 1) + '</td>' +
                            td + '" title="点击可复制">' + (postData.question.match('<img') ? postData.question : postData.question.replace(/&/g, '&amp;').replace(/</g, '&lt')) + '</td>' +
                            td + '" title="点击可复制">' + obj.data.answer +'</td>' +
                        '</tr>'
                    ).appendTo(setting.div.find('tbody')).css('background-color',YiBinFillAnswer($TiMu.find('.test-options').find('.t-option'), obj, postData) ? '' : 'rgba(0, 150, 136, 0.6)');
                   setting.num++;
                } else if(obj.code == 110 || obj.code == 104){
                    setting.div.children('div:eq(0)').html(obj.msg);
                } else if (obj.code == 102 || obj.code == 305){
                    setting.div.children('div:eq(0)').data('html', obj.msg).siblings('button:eq(1)').click();
                    window.open('http://lyck6.cn/api/regist.php')
                } else{
                    setting.div.children('div:eq(0)').html('发现未知异常，请联系QQ1666888816报告反馈bug').siblings('button:eq(1)').click();;
                }
                //setting.div.children('span').html(obj.msg || '');
            } else if (xhr.status == 403) {
                setting.div.children('div:eq(0)').data('html', '由于你的请求过于频繁，您的ip已被封<br>10分钟后自动解封<br>或者使用token答题不限制请求次数').siblings('button:eq(1)').click();
            } else if (xhr.status == 404) {
                setting.div.children('div:eq(0)').data('html', '最新版已发布！请点击油猴按钮【用户脚本检查更新】完成更新！').siblings('button:eq(1)').click();
            }else {
                setting.div.children('div:eq(0)').html('发现未知异常，请联系QQ1666888816处理');
            }
        },
        ontimeout: function() {
            setting.loop && setting.div.children('div:eq(0)').html(setting.over + '正在链接到云端，请稍后....<br>如果长时间链接不上请联系QQ1666888816');
        }
    });
}

function YiBinFillAnswer($option,obj ,postData){
     var str = String(obj.data.answer).toCDB().replace(/;$/,''),
        data = str.split(/#|\x01|\|/),
        state = setting.lose,
        flag = false;
    obj.data.success && $option.each(function() {
        let tip = String(filterImg($$(this).find('p'))).toCDB().replace(/;$/,'');
        if (tip.match(/(正确|是|对|√|T|ri)$/)) {
            data.join().match(/(^|,)(正确|是|对|√|T|ri)(,|$)/) && setting.queue.push(this);
        } else if (tip.match(/(错误|否|错|×|F|wr)$/)) {
            data.join().match(/(^|,)(错误|否|错|×|F|wr)(,|$)/) && setting.queue.push(this);
        } else if (postData.type == 1) {
            Boolean($$.inArray(tip, data) + 1 || str.indexOf(tip) + 1) == Boolean($$(this).find('.selected').length) || setting.queue.push(this);
        } else {
            $$.inArray(tip, data) + 1 && setting.queue.push(this);
        }
    });
    if (setting.queue.length) {
    } else if (/^(0|1|3)$/.test(postData.type)) {
        Boolean($option.find('.selected').length) || (setting.none ? setting.queue.push($option.eq([Math.floor(Math.random() * $option.length)])) : setting.lose++);
    } else if (/^(2)$/.test(postData.type)) {
        //暂时没有人提供其他类型的题目
    } else {
        setting.none || setting.lose++;
    }
    return state == setting.lose ? true : reportProblem(postData);
}
