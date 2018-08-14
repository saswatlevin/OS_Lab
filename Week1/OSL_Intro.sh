#1.
#i)
mkdir dir_exp
cd dir_exp
mkdir subdir1
mkdir subdir2

#ii)
cd dir_exp
cat > f1.txt
cat > f2.txt
cat > f3.txt

#iii)
cp exp.txt /home/student/dir_exp/subdir1

#iv)
cat > num.txt
who|wc -l >> num.txt
ls -l|grep "^-"|wc -l >> num.txt


#v)
ls a* && ls A*

#vi)
ls -l|grep "^-"|wc -l

#vii)
cc hello.c && ./a.out||who 'Error'

#viii)
wc -l|cat > count.txt

#2.
date && ls && pwd
