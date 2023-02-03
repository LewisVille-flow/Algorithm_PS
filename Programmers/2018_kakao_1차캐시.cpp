/*
    15:01- 15:48
    예외: 대소문자 구분, 캐시 크기 0
*/
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string ToLower(string s){
    transform(s.begin(), s.end(), s.begin(),
             [](unsigned char c){ return std::tolower(c); }
             );
    return s;
}

// 2차 풀이
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
  
    for(int c=0; c<cities.size(); c++){
        bool found_flag = false;
        int found_idx = -1;
        // 0. lower case
        
        string city_now = ToLower(cities[c]);
        //string city_now = cities[c];
        for(int i=0; i<cache.size(); i++){
            if(cache[i] == city_now){
            
            //if(strcasecmp(cache[i].c_str(), city_now.c_str()) == 0){
                found_flag = true;
                found_idx = i;
                break;
            }
        }
        
        // 1. cache hit
        if(found_flag){
            // remove and push again
            cache.erase(cache.begin()+found_idx);
            cache.push_back(city_now);
            answer += 1;
        }
        // 2. cache miss
        else{
            if(cacheSize == 0){
                answer += 5;
                continue;
            }
            // 2-1. cache not full
            //if(cache.size() < cacheSize){}
            // 2-2. cache full
            if(cache.size() >= cacheSize)
                cache.erase(cache.begin());
            
            cache.push_back(city_now);
            answer += 5;
        }
    }    
    return answer;
}



/*
// 1차 풀이
vector<pair<string, int>> cache;

vector<pair<bool, int>> Check(string city){
    vector<pair<bool, int>> answer;
    if(cache.size() == 0){
        answer.push_back({false, -1});
        return answer;
    }
    for(int i=0; i<cache.size(); i++){
        if(strcasecmp(cache[i].first.c_str(), city.c_str()) == 0){
            answer.push_back({true, i});
            return answer;
        }
    }
    answer.push_back({false, -1});
    return answer;
}


int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    
    for(int i=0; i<cities.size(); i++){
        
        bool check = Check(cities[i])[0].first;
        int idx = Check(cities[i])[0].second;
        
        if(cache.size() < cacheSize && !check || cacheSize == 0){
            cache.push_back({cities[i], 1});
            answer += 5;
            continue;
        }
        
        if(check){
            string name = cache[idx].first;
            int num = cache[idx].second + 1;
            cache.erase(cache.begin()+idx);
            cache.push_back({name, num});
            answer += 1;
            continue;
        }
        
        if(cache.size() >= cacheSize && !check){
            cache.erase(cache.begin());
            cache.push_back({cities[i], 1});
            answer += 5;
        }
    }
    return answer;
}
*/