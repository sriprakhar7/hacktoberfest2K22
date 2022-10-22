#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<utility>
#include<math.h>
#include<algorithm>
#include<fstream>
double find_dist(pair<int,int> p1, pair<int,int> p2)
{
	double d;
	int x_dis,y_dis;
	x_dis = p1.first-p2.first;
	y_dis = p1.second - p2.second;
	//cout<<x_dis<<"   "<<y_dis;
	d = sqrt(x_dis*x_dis + y_dis*y_dis);
	return d;
}
int main()
{
	map<double,vector<pair<int,int> > > map_dist;
	vector<pair<int,int> > points;
	pair <int,int> point;
	pair <int,int> qpoint;
	int i,n,x,y;
	double dist;
	ifstream fin;
	//or, char name[80];
	//cin>>name; fin.open(name);
	fin.open("points.txt");
	if (!fin)
	cout<<"Error";
	else
	{
	fin>>n;    //Converting cin to fin
	for(i=0;i<n;i++)
	{
		fin>>x>>y;
		point = make_pair(x,y);
		points.push_back(point);
	}
	fin>>x>>y;
	qpoint = make_pair(x,y);
	fin.close();
	}
	for(i=0;i<points.size();i++)
	{
//		cout<<points[i].first<<"   "<<points[i].second<<endl;
		dist = find_dist(points[i],qpoint);
	//	cout<< dist<<endl;
		if (map_dist.find(dist)!=map_dist.end())
		map_dist[dist].push_back(points[i]);
		else
		{
		vector<pair<int,int> >  new_vec;
		new_vec.push_back(points[i]);
		map_dist[dist] = new_vec;
		}
	}
    vector<double> dist_vec;
	for(i=0;i<points.size();i++)
	cout<<points[i].first<< "   "<<points[i].second<<endl;
	
	//Auto won't work
    /*for(auto d:map_dist)
    dist_vec.push_back(d.first);
    sort(dist_vec.begin(),dist_vec.end());
    for (auto ele:dist_vec)
    for(auto v:map_dist[ele])
    cout<<v.first<<"  "<<v.second<<endl;	*/
}

