class Solution {
public:
    int threeSumClosest(vector<int>& A, int B) {
      sort(A.begin(),A.end());
    int a,b,c;
    a=0;
    b=1;
    c=A.size()-1;
    if(A.size()==3)
    return A[a]+A[b]+A[c];
    int temp=abs(B)-abs(A[a]+A[b]+A[c]);
    int minTemp=INT_MAX;
    
    int sum=A[a]+A[b]+A[c];
    for(;a<A.size()-2;a++)
    {
        b=a+1;
        c=A.size()-1;
        while(b<c)
        {
            temp=abs(B-(A[a]+A[b]+A[c]));
            if(temp<minTemp)
            {
                minTemp=temp;
                sum=A[a]+A[b]+A[c];
            }
            if(A[a]+A[b]+A[c]==B)
            return B;
            if(A[a]+A[b]+A[c]>B)
            c--;
            else if(A[a]+A[b]+A[c]<B)
            b++;
        }
        
    }
    return sum;  
    }
};
