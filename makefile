all :
	g++ main.cpp -o main -std=c++20 -O3 
git :
	git init
	git add README.md
	git commit -m "first commit"
	git branch -M main
	git remote add origin https://github.com/ysf125/lineAlgorithm.git
	git push -u origin main