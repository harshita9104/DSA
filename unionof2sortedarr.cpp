//brute - using set
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        int i,j ;
        i = j = 0;
        set<int>ans;
        //Add the element of both the arrays into the set, it will take care of duplicates.
        // and at last copy the elements of the set into the vector.
        
        vector<int>a;
        
        while(i < n)
            ans.insert(arr1[i++]);
        while(j < m)
            ans.insert(arr2[j++]);
        
        for(auto it: ans){
            a.push_back(it);
        }
            
        return a;
    }
//mistake- segmentation error may occur if you dont initialise pointers to 0 , also include the condition in else that what ifboth the elements are equal
//optimal - using 2 pointers
//arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        int i = 0;
    int j = 0;
    vector<int> unionarr;

    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            if (unionarr.size() == 0 || unionarr.back() != arr1[i]) {
                unionarr.push_back(arr1[i]);
            }
            i++;
        } else if (arr1[i] > arr2[j]) {
            if (unionarr.size() == 0 || unionarr.back() != arr2[j]) {
                unionarr.push_back(arr2[j]);
            }
            j++;
        } else {
            // Both elements are equal
            if (unionarr.size() == 0 || unionarr.back() != arr1[i]) {
                unionarr.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }

    while (i < n) {
        if (unionarr.size() == 0 || unionarr.back() != arr1[i]) {
            unionarr.push_back(arr1[i]);
        }
        i++;
    }

    while (j < m) {
        if (unionarr.size() == 0 || unionarr.back() != arr2[j]) {
            unionarr.push_back(arr2[j]);
        }
        j++;
    }

    return unionarr;

    }