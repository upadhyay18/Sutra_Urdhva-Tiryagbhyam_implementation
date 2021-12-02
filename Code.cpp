#include<bits/stdc++.h>
using  namespace std;
class vadikMUltiplication{
    private:
        vector<int> num1,num2;
        vector<int>ans;
        void multiply(){
            int size=num1.size();
            for(int i=0;i<size;i++){
                int sum=0;
                int k=i;
                for(int j=0;j<i+1;j++){
                    sum+=num1[k]*num2[j];
                    k--;
                }
                //cout<<sum<< " ";
                ans.push_back(sum);
            }
            for(int i=1;i<size;i++){
                int sum=0;
                int k=size-1;
                for(int j=i;j<size;j++){
                    sum+=num1[k]*num2[j];
                    k--;
                }
                ans.push_back(sum);
            }
        }
    public:
        void assign(string s1,string s2){
            int i1=0, n1=s1.size();
            int i2=0, n2=s2.size();
            while(n1>n2){
                num2.push_back(0);
                num1.push_back(s1[i1]-'0');
                --n1;++i1;
            }
            while(n1<n2){
                num1.push_back(0);
                num2.push_back(s2[i2]-'0');
                n2--;++i2;
            }
            while(n1!=0){
                num1.push_back(s1[i1]-'0');
                num2.push_back(s2[i2]-'0');
                ++i1;
                ++i2;
                --n1;
            }
        }
        void getAns(){
            multiply();
            int size=ans.size();
            int carry=0;
            num1.clear();
            num2.clear();
            for(int i=size-1;i>=0;i--){
                int temp=(ans[i]+carry);
                ans[i]=temp%10;
                carry=temp/10;
            }
            if(carry>0)
                cout<<carry;
            //loop to remove prior zeros
            int i=0;
            for(;i<size;i++)
                if(ans[i]!=0)
                    break;
            for(;i<size;i++)
                cout<<ans[i];

            cout<<endl;
        }

};
//main code form here
int main(){
    string s1,s2;
    cout<<"\nEnter 1st No: ";cin>>s1;
    cout<<"\nEnter 2nd No: ";cin>>s2;
    vadikMUltiplication vm;
    vm.assign(s1,s2);
    cout<<"-----------\ngiven-\nnum1 = "<<s1<<"\nnum2 = "<<s2<<"\nSo num1 * num2 = ";
    vm.getAns();
    return 0;
}