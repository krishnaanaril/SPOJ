//        /*
//            SPOJ: HEADSHOT
//            Status:
//            Date: 8/19/2014
//        */
//
//        #include <bits/stdc++.h>
//
//        using namespace std;
//
//        int main()
//        {
//            string str;
//            int pos=0,neg=0,n, num0=0;
//            cin>>str;
//            n=str.size();
//            for(int i=0;i<n;i++)
//            {
//                if(str[i]=='0')
//                {
//                    num0++;
//                }
//                //cout<<str[(i+1)%n]<<endl;
//                if(str[i]=='0' && str[(i+1)%n]=='0')
//                {
//                    pos++;
//                }
//                else if(str[i]=='0' && str[(i+1)%n]=='1')
//                {
//                    neg++;
//                }
//            }
//            //cout<<"Pos: "<<pos<<endl<<"Neg: "<<neg<<endl;
//            n=neg!=0?pos/neg:pos;
//            //cout<<n<<endl;
//            if(n==1)
//            {
//                cout<<"EQUAL"<<endl;
//            }
//            else if(n>1)
//            {
//                cout<<"SHOOT"<<endl;
//            }
//            else
//            {
//                cout<<"ROTATE"<<endl;
//            }
//            return 0;
//        }
