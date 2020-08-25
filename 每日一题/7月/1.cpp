hugo new site myblog

git clone https://github.com/digitalcraftsman/hugo-agency-theme

hugo server -t hugo-agency-theme --buildDrafts

hugo new post/blog.md

hugo --theme=hugo-agency-theme --baseUrl="https://lastknightcoder.github.io/" --buildDrafts

cd public

git init

git add .

git commit -m "我的 hugo 博客第一次提交"

git remote add origin https://github.com/LastKnightCoder/lastknightcoder.github.io.git

git pull origin master --allow-unrelated-histories(我第二次换主题的时候用了这个)

git push -u origin master