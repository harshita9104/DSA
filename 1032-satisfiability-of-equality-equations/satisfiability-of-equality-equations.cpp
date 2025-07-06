class Solution {
public:
//ye q map se bhi ho skta hai jo elem ek dusre k eq h unko map m daalo track kro 
//or last m ye check kro ki ky not eq elem sach m not eq h
//but with dsu it is is as we need to find that do these elem belong to same set or not
//where ek set m vo elem h jo aapas m eq h
//first write the optimised find by path compression
    int find(int x,  vector<int> &par){//a func which return par of x
        //this par vector keeps track of par of a set
        //if a par or leader of a set is a that element itself then return
        //but if its not then rec call find passing its par 
        //and whatever rec call returns update the par[i] with that value
        if(x == par[x]){
            return x;//x khud hi khud ka par h to return kardo taaki iske set m jo elem h unko bhi par mil jae
        }
        return par[x] = find(par[x], par);//rec call se jo return hoke aaya usko x ka leader manlo
    }
    //optimised union method using rank initially rank of all elem is 1 and each elem is par of itself
    //agar 2 sets ka union krna h to kisi ek ko dusre ka par bna do, unki rank dekho
    //agar rank same hai to union kro kisiko bhi merged set ka par bna do jisko bnaya h uski rank++
    //agar rank same nhi h to jiski rank badi h usko dusre wale set ka par banao , rank dont inc
    void unionset(int x, int y, vector<int> &par, vector<int> &rank){
        int x_par = find(x, par);
        int y_par = find(y, par);
        if(x_par == y_par)return;// it means dono same set m h union nhi krna 
        if(rank[x_par] > rank[y_par]){
            par[y_par] = x_par;//x k leader ki rank badi h to usko hi y ka leader bna do
        }else if(rank[x_par] < rank[y_par]){
            par[x_par] = y_par;
        }else{
            //when rank is eq kisiko bhi par bnalo uski rank inc krdena
            par[x_par] = y_par;
            rank[y_par]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        vector<int> par(26);
        vector<int> rank(26, 0);
        for(int i =0; i< 26; i++){
            par[i] =i;
        }
        //is loop se hmne eq elem ko ek set m daaldiya
        for(string &s : equations){
            if(s[1] == '='){
                //union krna h 0th or 3rd index elem ka
                unionset(s[0]-'a', s[3]-'a', par, rank);
            }
        }
        for(string &s : equations){
            if(s[1] != '='){
               //ab find kro ky dono same set k h agar hai to dono eq h ye equation ki ye not eq honge false h
               int par_first = find(s[0]-'a', par);
               int par_second = find(s[3] - 'a', par);
               if(par_first == par_second)return false;
            }
        }
        return true;
    }
};