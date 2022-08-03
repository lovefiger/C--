### 提交代码
~~~
  # 提交代码
  git commit -m "first commit"
  # 设置远程仓库
  git remote add origin git@github.com:lovefiger/C--.git
  # 推送代码到远程仓库
  git push origin master 
~~~

### 更新代码
~~~
# 从远程的origin仓库的master分支下载代码到本地的origin master
$ git fetch origin master 
# 比较本地的仓库和远程参考的区别
$ git log -p master.. origin/master
# 把远程下载下来的代码合并到本地仓库，远程的和本地的合并
$ git merge origin/master
~~~
