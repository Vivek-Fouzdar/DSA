 //Union of Two Sorted Array
 #include<bits/stdc++.h>
 using namespace std;
 
 vector<int> findUnionHashmap(vector<int> &a, vector<int> &b) {
        // code here
        map<int,int> Hashmap;
        vector<int> Union;
        int n = a.size();
        int m = b.size();
        
        for(int i = 0 ; i<n;i++)
        {
            Hashmap[a[i]]++;
        }
        
        for(int i = 0 ; i<m;i++)
        {
            Hashmap[b[i]]++;
        }
        
        for(auto &it : Hashmap)
        {
            Union.push_back(it.first);
        }
        return Union;
    }

    vector<int> findUnionSet(vector<int> &a, vector<int> &b)
    {
        int n = a.size();
        int m = b.size();
        set<int> st;

        for(int i =0; i<n;i++)
        {
            st.insert(a[i]);
        }

        for(int i =0; i<m;i++)
        {
            st.insert(b[i]);
        }

        vector<int> Union(st.begin(),st.end());
        return Union;
    }

    vector<int> findUnionTwopointers(vector<int> &a,vector<int> &b)
    {
        int n = a.size();
        int m = b.size();
        vector<int> ans;
        int i = 0;
        int j = 0;
        while(i < n && j<m )
        {
            if(a[i] <= b[j])
            {
                if(ans.size() == 0 || a[i] != ans.back())
                {
                    ans.push_back(a[i]);
                }
                i++;
            }
            else
            {
                if(ans.size() == 0 || b[j] != ans.back())
                {
                    ans.push_back(b[j]);
                }
                j++;
            }
        }

        while(i<n)
        {
            if(a[i] != ans.back())
            {
                ans.push_back(a[i]);
            }
            i++;
        }

        while(j<m)
        {
            if(b[j] != ans.back())
            {
                ans.push_back(b[j]);
            }
            j++;
        }
        return ans;

    }

    int main()
    {
        vector<int> arr1 = {1,2,3};
        vector<int> arr2 = {2,3,4};
        vector<int> ans = findUnionTwopointers(arr1,arr2);
        for(auto &it:ans)
        {
            cout<<it<<" ";
        }
        return 0;
    }