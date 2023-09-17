#include<iostream>
#include<conio.h>
#include<vector>
using namespace std;


int transactionhistory(vector<string>& historyc,vector<int>& historyv,double& total){
	if(total>0){
        for(int i=0;i<historyc.size();i++){
            cout<<i+1<<"-"<<historyc[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<historyc.size();i++){
            cout<<"  "<<historyv[i]<<"  ";
        }
        cout<<endl<<endl<<endl;
        cout<<"Total Amount: "<<total<<endl<<endl;
    }
    else{
        cout<<"Your account balance is "<<total<<" Rs\n"<<endl;
    }	
}


int withdrawmoney(vector<string>& historyc,vector<int>& historyv,double& total){
	int withdraw;
	cout<<"Enter money to withdraw: ";
	cin>>withdraw;
	cout<<endl;
    if(total>withdraw){
        total-=withdraw;
        historyc.push_back("debit ");
        historyv.push_back(withdraw);
        cout<<"You have successfully debited.. "<<withdraw<<" Rs\n"<<endl;
    }
    else{
        cout<<"you have not enough balance.."<<endl<<endl;
    }
	
}


int depositmoney(vector<string>& historyc,vector<int>& historyv,double& total){
	int deposit;
	cout<<"Enter money to deposit: ";
	cin>>deposit;
	cout<<endl;
	total+=deposit;
    historyc.push_back("credit");
    historyv.push_back(deposit);
	cout<<"You have succesfully credited "<<deposit<<" Rs\n"<<endl;
}


int main(){
    int ch;
    vector<string> historyc;
    vector<int> historyv;
    double total=0;
    do{
        cout<<"To check transcation history press 1: \n";
        cout<<"to withdraw money press 2: \n";
        cout<<"To deposit money press 3: \n";
        cout<<"To transfer money press 4: \n";
        cout<<"To exit press 5: \n";
        cout<<endl<<"enter choice: ";
        cin>>ch;
        cout<<endl;
        switch(ch){
            case 1:
                transactionhistory(historyc,historyv,total);
                break;
            case 2:
                withdrawmoney(historyc,historyv,total);
                break;
            case 3:
                depositmoney(historyc,historyv,total);
                break;
            case 4:
                cout<<"this process is not available  now...."<<endl;
        }
    }while(ch!=5);
    getch();
}
