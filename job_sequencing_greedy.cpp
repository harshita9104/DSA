// You are given two arrays: deadline[], and profit[], which represent a set of jobs, where each job is associated with a deadline, and a profit. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline.

// Your task is to find:

// The maximum number of jobs that can be completed within their deadlines.
// The total maximum profit earned by completing those jobs.
class Solution {
  public:
  bool static comp(pair<int, int> &p1, pair<int, int> &p2){
      return p1.first > p2.first;
  }
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        
        int n = deadline.size();
        //ab profit ko corresponding deadline k sath ek pair m vector m store krlo taki baad m is vector ko hm pair ki first val k basis pr sort kr pye
        vector<pair<int, int>> v;
        for(int i =0; i<n; i++){
            v.push_back({profit[i], deadline[i]});
        }
        sort(v.begin(), v.end(), comp);//profit k basis par ye vector m jobs align ho gyi desc order m
        
        // iske baad ek aisa arr banao  jiska index denote day and val is job id allocated to that day
        vector<int> jobfill(n+1, -1);//max days can be n and initially no job is allocated so -1
        
        int totalprofit =0;
        int totaljobs=0;
        
        for(int i =0; i<n; i++){
            int gain = v[i].first;//max profit sabse phle aayega 
            int deadline = v[i].second;//ye uski deadline
            
            //ab mai max deadline jo hai vahi wala din allocate krne ka try krungi agar vo free nhi h to uske phle wala koi
            for(int j = deadline; j>0; j--){
                //hm piche se allocate krenge taaki jinki deadline kam h unko bhi slot mile
                if(jobfill[j] == -1){
                    //this day is free
                    jobfill[j] = i;//ye wali job id jiske liye hm slot dhundh rhe the usko ye day allocate krdo
                    totalprofit += gain;//or uska profit m add krdo
                    totaljobs++;
                    break;//since ith job id ko allocate ho gya day loop break krdo
                }
            }
        }
        return {totaljobs, totalprofit};
        
    }
};
