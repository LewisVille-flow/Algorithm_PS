/*
    21:24-21:55, 31m
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int NR_MAX = 1001;
int NC, NR;
int student[NR_MAX];
vector<pair<int, int>> final_candidate;

void Decide_Candidate(int rec_student){
    int size = final_candidate.size();
    //
    for(int i=0; i<size; i++){
        if(final_candidate[i].first == rec_student){
            final_candidate[i].second += 1;
            return;
        }
    }

    //
    if(size == NC){
        int min_rec_stu = final_candidate.front().second;
        int min_rec_stu_idx=0;
        for(int i=1; i<size; i++){
            if(final_candidate[i].second < min_rec_stu){
                min_rec_stu = final_candidate[i].second;
                min_rec_stu_idx = i;
            }
        }
        final_candidate.erase(final_candidate.begin()+min_rec_stu_idx);
        final_candidate.push_back(make_pair(rec_student, 1));
        return;
    }
    else if(size < NC)
        final_candidate.push_back(make_pair(rec_student, 1));
    
    return;
}

void Solve(){
    int _in;
    cin >> NC >> NR;
    for(int i=0; i<NR; i++){
        cin >> _in;
        Decide_Candidate(_in);
    }

    sort(final_candidate.begin(), final_candidate.end());

    for(int f=0; f<final_candidate.size(); f++)
        cout << final_candidate[f].first << " ";
}

int main(){
    Solve();
    return 0;
}