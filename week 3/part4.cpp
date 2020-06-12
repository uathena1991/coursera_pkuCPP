#include <iostream>
#include <string>
#include <map>
#include <deque>
#include <array>
#include <sstream>
#include <stdio.h>
//#include<bits/stdc++.h>

using namespace std;

string int2string(int t, int decim = 3){
    stringstream ss;
    ss << t;
    return string((decim - ss.str().size()), '0') + ss.str();
}

class Warrior {
public:
    string name;
    int hp, dp;
    Warrior(string n, int h, int d = 1):name(n), hp(h),dp(d){};
};

class HQ{
public:
    int count, total_hp;
    bool istop;
    string type; // red or blue
    deque<Warrior> queue;
    map<string, int> w_count;
    // constructor
    HQ(int hp,  string t, deque<Warrior> q,array<Warrior, 5> W_list, array<int, 5> ar): count(0),type(t),total_hp(hp){
        int min_ele = INT_MAX;
        for(int i=0;i<ar.size();i++){
            w_count[W_list[ar[i]].name] = 0;
            q.push_back(W_list[ar[i]]);
            min_ele = (min_ele < W_list[ar[i]].hp)?min_ele: W_list[ar[i]].hp;
        }
        istop = hp <= 0 || hp < min_ele;
        queue = q;
        //        cout << endl;
    }
    
    // create new warrior
    bool create(int time){
        if (not istop){
            while(!queue.empty() & (queue.front().hp > total_hp)){
                queue.pop_front();
            }
            if (queue.empty()){
                istop = true;
                printf("%s %s headquarter stops making warriors\n", int2string(time).c_str(), type.c_str());
                return not istop;
            }
            Warrior curr = queue.front();
            queue.pop_front();
            total_hp -= curr.hp;
            w_count[curr.name] += 1;
            count += 1;
            //print
            printf("%s %s %s %d born with strength %d,%d %s in %s headquarter\n", int2string(time).c_str(), type.c_str(), curr.name.c_str(),
                   count, curr.hp, w_count[curr.name], curr.name.c_str(), type.c_str());
            queue.push_back(curr); // put it in the back of the quseue;
            return not istop;
        }
        else{
            return not istop;
        }
    }
};

int main(){
    const int num_warrior = 5;
    int test_num, max_hp;
    int *hps = new int[num_warrior];
    // unchanged varibles
    const array<int, 5> red_order = {2,3, 4, 1, 0};
    const array<int, 5> blue_order = {3,0, 1, 2, 4};
    //get input
    cin >> test_num;
    
    for(int cid = 1; cid <= test_num;cid ++){
        // create objects(variables)
        int time = 0;
        cin >> max_hp;
        for (int i=0;i<num_warrior;i++){
            cin >> hps[i];
        }
        array<Warrior, 5> W_list = {Warrior("dragon", hps[0]), Warrior("ninja", hps[1]),
            Warrior("iceman", hps[2]),
            Warrior("lion", hps[3]), Warrior("wolf", hps[4])};
        deque<Warrior> red_queue, blue_queue;
        HQ red(max_hp, "red", red_queue, W_list, red_order), blue(max_hp, "blue", blue_queue, W_list, blue_order);
        red_queue.clear(), blue_queue.clear();
        // print
        cout << "Case:" << cid << endl;
        if (red.istop){printf("%s %s headquarter stops making warriors\n", int2string(time).c_str(), red.type.c_str());}
        if (blue.istop){printf("%s %s headquarter stops making warriors\n", int2string(time).c_str(), blue.type.c_str());}
        while (not (red.istop and blue.istop)){
            // create new warrior:
            red.create(time);
            blue.create(time);
            time += 1;
        }
    }
    
    return 0;
}
