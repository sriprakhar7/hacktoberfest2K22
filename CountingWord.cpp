#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<map>
#include<utility>
#include<fstream>
#include<algorithm>
int main()
{
	ifstream file1;
	map<string,int> word_count;
	string word;
	string fname;
	vector<string> words;
	cin>>fname;
	file1.open(fname);
	while(!file1.eof())
	{
		file1>>word;
		if(!file1.eof())
		{
		if (word_count.find(word)==word_count.end()) //not found, so adding it
		word_count[word]=1;
		else
		word_count[word]++;  //it was there in the map so just increment the value
		}
	}
	for(auto &a:word_count)
	words.push_back(a.first);
	sort(words.begin(),words.end());
	for (auto &word:words)
	cout<<word<<"   "<<word_count[word]<<endl;
	file1.close();
}
