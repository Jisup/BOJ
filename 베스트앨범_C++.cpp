#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <set>

#define MAX 10001
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
	int index = 1;
	int Size = genres.size();

	vector<int> answer;
	map <string, int> m;
	map <string, int> type;
	vector <pair<int, int> > list[MAX];
	int record[MAX] = { 0, };

	//중복된장르의 plays크기에따른 순서 = vector
	for (int i = 0; i < Size; i++) {
		//노래의총합 = m
		m[genres[i]] += plays[i];
		//classic=1, pop=2;
		if (type[genres[i]] == 0) {
			type[genres[i]] = index++;
		}
		list[type[genres[i]]].push_back(make_pair(plays[i], i));
	}

	vector<pair<int, int> > song;
	for (auto it : m)
		song.push_back({ it.second, type[it.first] });
	sort(song.begin(), song.end(), [](pair<int, int>a, pair<int, int>b) {
		if (a.first == b.first)
			return a.second < b.second;
		return a.first > b.first;
	});

	int Size2 = type.size();
	for (int i = 1; i <= Size2; i++)
		sort(list[i].begin(), list[i].end(), [](pair<int, int>a, pair<int, int>b) {
		if (a.first == b.first)
			return a.second < b.second;
		return a.first > b.first;
	});
	for (int i = 0; i < song.size(); i++) {
		int index = song[i].second;
		for (int k = 0; k < list[index].size(); k++) {
			if (k > 1) break;
			answer.push_back(list[index][k].second);
		}
	}
	return answer;
}