class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l=0,u=letters.size()-1;
        int mid;
        if(target>=letters[letters.size()-1])
            return letters[0];
        while(l<u)
        {
            mid=(l+u)/2;
            if(letters[mid]<=target)
                l=mid+1;
            else
                u=mid;
        }
        if(letters[mid]<=target)
            mid++;
        return letters[mid];
    }
};
