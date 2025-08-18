class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //hme sirf freq ko dekhna h jaise hi ek task ko complete kro uski freq-- krdo
        //is task ki  updated freq ko  pq m vapis tabhi daal payenge jab n tasks or comeplete ho jae kyuki ye char ab n internvel baad hi aa skta 
        //max heap bnega kyuki hme phle vo task karne h har baar jinki freq jyada h taaki end m inko idle intervel k sath na karna pad jaye
        vector<int> mp(26, 0);//char ki freq k liye
        for(char &ch : tasks){
            mp[ch-'A']++;
        }
        int time =0;
        priority_queue<int> pq;//ye sirf fre store krega hm vapis sirf pos freq ko daalenge agar ye empty ho gyi mtlb sare tasks complete ho gye
        //jab tak koi non zero freq present h  maxheap m tab tk n+1 tasks complete honge ek baar m 
        //jab pq empty ho jae yaani ab tasks nhi bache h jitna ho paya utna tasks kro
        for(int i =0; i<26; i++){
            if(mp[i] >0){
                pq.push(mp[i]);//sirf kisi char ki freq heap m daalenge
                //is loop k baad sare tasks ki freq heap m aagyi h
            }
        }
        while(!pq.empty()){
            //agar ek task ko maine pop kiya to ab n wait krke hi mai uski freq ko pq m daal skti phirse
            //yani mai jis task ko nikal rhi uski freq -1 krke phirse tabhi daal skti jab n tasks or complete krlu , vo n tasks krne k liye pq se hi nikalna pdega ek baar ye n+1 tasks ho jae phir pq m inko phirse dalna updated freq k sath non zero freq hi dalna
            //ek baar m ek sath aap pq se n+1 tasks hi nikal skte
            vector<int> temp;//konse tasks nikal rhe pq se baad m daalna hoga tab yha se daaldenge
            for(int i = 1; i<= n+1; i++){
                //n+1 tasks tabhi kr skte jab pq empty n ho
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    freq--;//isko complete kr lia lekin jab tak n tasks complete n ho isko pq m nhi daal skte isliye isko temp m store krleneg
                    temp.push_back(freq);
                }
            }//n+1 tasks kr liyeab inki updated freq pq m daalo
            for(int &f : temp){
                if(f>0)pq.push(f);
            }
            //agar pq empty ho gya yani ab or task nhi krne to time m temp.size() hi hoga yani jitne tasks ho paye sirf utne lekin pq empty nhi hua to phir n+1 tasks honge
            if(pq.empty())time += temp.size();
            else time += n+1;
        }
        return time;
    }
};