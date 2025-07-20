class Solution {
public:
//tokeni jitna power ghata kar score++ kr skte
//score-- kar tokerni jitna power gain kr skte 
//since we need to maximise score first i will think of gaining score by reducing power and if i have at least 1 score then i will think of gaining power but i would like to gain the maximum power avail in tokens so that after this i can maximise my score
//so i will sort tokens so that when i need to inc power i will go to the last token
//and place i pointer in  beginning and j pointer at end
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int maxscore = 0;//we are doing this kyuki score bdhane k baad if we will experiment with dec score and inc power and then see what the score is to ho skta h score utna na badhe to maxscore phle hi preserve krlo
        int score =0;
        int i =0;
        int j = tokens.size()-1;
        while(i<=j){
            //phle score inc krne ki cond
            if(power>= tokens[i]){
                power -= tokens[i];
                score++;
                i++;
                //max score store krlo ky pta baad m itna nahi pahuch paye
                maxscore = max(maxscore, score);
            }else if (score >= 1){
                power += tokens[j];
                score--;
                j--;
            }else{
                //if both the cases are not possible 
                return maxscore;
            }
        }
        return maxscore;

    }
};