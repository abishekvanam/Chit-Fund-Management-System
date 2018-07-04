#include <iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;
class chit1
{
    int chit_value, amount_choice, bid_amount, num_inv, inv_choice, org_comission, num_months, monthly_pay_amount, present_month,finalIDs[50],finalBids[50],finall;
    char inv_names[50][20];
    int month,id[50],amount[50];
    char name[50][20],fname[20];
public:
    chit1();
    void getChitDetails();
    void inv_choiceInput();
    void chitDescription();
    void getInvDetails();
    void showInvDetails();
    void bid();
    void finalDetails();
};
chit1::chit1()
{
    present_month=1;
    finall=0;
}
void chit1::getChitDetails()
{
    cout<<"You have the following chit amounts!"<<endl;
    cout<<"1. 1 lakh Chit\n2. 3 lakh Chit\n3. 5 lakh Chit"<<endl;
    cout<<"Enter your choice : ";
    cin>>amount_choice;
    switch(amount_choice)
    {
        case 1: chit_value=100000;
                break;
        case 2: chit_value=300000;
                break;
        case 3: chit_value=500000;
                break;
        default:    cout<<"Invalid Choice! Try again!"<<endl;
    }
}
   void chit1::inv_choiceInput()
{


    cout<<"Available number of Investors : 2\t5\t10\t20\t25\n";
    cout<<"Enter your choice : ";
    cin>>inv_choice;
    org_comission=chit_value*0.05;
    num_months=inv_choice;
    monthly_pay_amount=chit_value/inv_choice;
}
void chit1::chitDescription()
{
    if(inv_choice==2||inv_choice==5||inv_choice==10||inv_choice==20||inv_choice==25)
    {


    cout<<"\n\nThis is "<<chit_value*0.00001<<" Lakh Chit with "<<inv_choice<<" investors paying Rs."<<monthly_pay_amount<<" per month for "<<num_months<<" months"<<endl;
    cout<<"Organizer commission per month Rs."<<org_comission<<endl<<endl;

    }
    else
    {
        cout<<"Enter the correct number of investors!!!";
        inv_choiceInput();
    }

}
void chit1::getInvDetails()
{
    for(int i=0;i<inv_choice;i++)
    {
        cout<<"Enter the name of the investor with ID number "<<i+1<<" : ";
        if(i==0)
        {
                cin.ignore();
        }
        cin.getline(inv_names[i],20);
    }
}
void chit1::showInvDetails()
{
    cout<<"\n\nInvestor Details :\n-----------------------\n";
    cout<<"Investor ID\tInvestor Name\n";
    for(int i=0;i<inv_choice;i++)
    {
            cout<<i+1<<"\t\t"<<inv_names[i]<<endl;
    }
    cout<<"Enter the file name (with extension) to store the investor details: ";
    cin>>fname;
}
void chit1::bid()
{
    int bidder_id, bid_amount, bidder_amount,continue_choice,maximum,bids[50],bidders[50],bid_winner=1,k,x,num_of_bidders,lucky_dip_id,dip_choice;
    float inv_amount;
    while(present_month<=num_months)
    {

        cout<<"\n\nBid Details for Month "<<present_month<<":\n-------------------------"<<endl;
        k=0;
        cout<<"Are there any investors interested in bidding?\n";
        cout<<"1.Yes\t2.No :::";
        cin>>x;
        if(x==1)
        {
            cout<<"Enter the number of investors interested in bidding:";
            cin>>num_of_bidders;
            cout<<"\n***** Make sure to avoid the investors who have already won the bidding!!! *****\n";
            cout<<"Enter the ID numbers of investors interested in bidding:";
            for(int i=0;i<num_of_bidders;i++)
            {
                cin>>bidders[i];
            }

            for(int i=0;i<num_of_bidders;i++)
            {
                cout<<"\nEnter the bid amount of investor "<<bidders[i]<<" :";
                cin>>bids[i];
                if(bids[i]<=org_comission)
                {
                    cout<<"Bid amount cannot be less that organizer commission :"<<org_comission<<endl;
                }
                else if(bids[i]>chit_value)
                {
                    cout<<"Bid amount cannot be greater than chit value :"<<chit_value<<endl;
                }


            }
            maximum=bids[0];
            bid_winner=bidders[0];
            for(k=1;k<num_of_bidders;k++)
            {
                if(bids[k]>maximum)
                   {

                    maximum=bids[k];
                    bid_winner=bidders[k];
                   }
            }
            bid_amount=maximum;
        }
        else
        {
            dip_choice=0;
            while(dip_choice!=2)
            {


                cout<<"\nLUCKY DIP\n";
                bid_amount=chit_value*0.1;
                cout<<"\nIn this lucky dip the bid value is fixed to "<<bid_amount;
                srand(time(0));
                lucky_dip_id=(rand()%inv_choice)+1;
                cout<<"\n\nID number "<<lucky_dip_id<<" :"<<inv_names[lucky_dip_id-1]<<" have won the lucky dip!!!";
                cout<<"\n\nEnter 1.    If ID:"<<lucky_dip_id<<" have already won bidding! \n\nEnter 2.    If ID:"<<lucky_dip_id<<" is a New winner!\n\nEnter your choice:";
                cin>>dip_choice;
            }
            bid_winner=lucky_dip_id;
        }




        finalIDs[finall]=bid_winner;
        finalBids[finall]=bid_amount;
        finall++;
        cout<<"\n---------------------------------------------------------------------------------------\n";
        cout<<"\nBid amount is :"<<bid_amount;
        cout<<"\n\nBidder ID :"<<bid_winner;
        cout<<"\n\nBidder : "<<inv_names[bid_winner-1]<<endl;

        bidder_amount=chit_value-bid_amount;
        cout<<"\nAmount to be given to bidder : Rs."<<bidder_amount<<endl;
        inv_amount=monthly_pay_amount-((bid_amount-org_comission)/(inv_choice));
        cout<<"\nAmount to be paid by the other investors : Rs."<<inv_amount<<endl;
        cout<<"\n---------------------------------------------------------------------------------------\n";

        ofstream out_id1,out_name1,out_amt_to_investor1;
        out_id1.open(fname,ios::app);
        //out_name1.open("names1.txt",ios::app);
        //out_amt_to_investor1.open("amounts1.txt",ios::app);
        out_id1<<bid_winner<<endl;
        out_id1<<inv_names[bid_winner-1]<<endl;
        out_id1<<bidder_amount<<endl;
       /* out_id1.close();
        out_name1.close();
        out_amt_to_investor1.close();*/




        ifstream in_id1,in_name1,in_amt_to_investor1;
        in_id1.open(fname);
        //in_name1.open("names1.txt");
        //in_amt_to_investor1.open("amounts1.txt");
        cout<<"CHIT DETAILS:\n---------------------------------------------------------------------------------------";
        cout<<"\n\nMONTH:\t     INVESTOR ID:\t      INVESTOR NAME:\t     AMOUNT TO INVESTOR:\n";
        cout<<"---------------------------------------------------------------------------------------";
            for(int i=0;i<present_month;i++)
            {
                in_id1>>id[i];
                in_id1>>name[i];
                in_id1>>amount[i];
                cout<<endl<<endl<<i+1<<"\t\t"<<id[i]<<"\t\t\t"<<name[i]<<"\t\t\t"<<amount[i];

            }
            in_id1.close();
           // in_name1.close();
           // in_amt_to_investor1.close();


        cout<<"\n\n********** END OF MONTH:"<<present_month<<" **********\n\n";
        present_month++;

        }
}

class chit2
{
    int chit_value, amount_choice, bid_amount, num_inv, inv_choice, org_comission, num_months, monthly_pay_amount, present_month,finalIDs[50],finalBids[50],finall;
    char inv_names[50][20];
    int month,id[50],amount[50];
    char name[50][20], fname[20];
public:
    chit2();
    void getChitDetails();
    void inv_choiceInput();
    void chitDescription();
    void getInvDetails();
    void showInvDetails();
    void bid();
    void finalDetails();
};
chit2::chit2()
{
    present_month=1;
}
void chit2::getChitDetails()
{
    cout<<"You have the following chit amounts!"<<endl;
    cout<<"1. 1 lakh Chit\n2. 3 lakh Chit\n3. 5 lakh Chit"<<endl;
    cout<<"Enter your choice : ";
    cin>>amount_choice;
    switch(amount_choice)
    {
        case 1: chit_value=100000;
                break;
        case 2: chit_value=300000;
                break;
        case 3: chit_value=500000;
                break;
        default:    cout<<"Invalid Choice! Try again!"<<endl;
    }
}
void chit2::inv_choiceInput()
{


    cout<<"Available number of Investors : 2\t5\t10\t20\t25\n";
    cout<<"Enter your choice : ";
    cin>>inv_choice;
    org_comission=chit_value*0.05;
    num_months=inv_choice;
    monthly_pay_amount=chit_value/inv_choice;
}
void chit2::chitDescription()
{
    if(inv_choice==2||inv_choice==5||inv_choice==10||inv_choice==20||inv_choice==25)
    {


    cout<<"\n\nThis is "<<chit_value*0.00001<<" Lakh Chit with "<<inv_choice<<" investors paying Rs."<<monthly_pay_amount<<" per month for "<<num_months<<" months"<<endl;
    cout<<"Organizer comission per month Rs."<<org_comission<<endl<<endl;

    }
    else
    {
        inv_choiceInput();
    }

}

void chit2::getInvDetails()
{
    for(int i=0;i<inv_choice;i++)
    {
        cout<<"Enter the name of the investor with ID num "<<i+1<<" : ";
        if(i==0)
        {
                cin.ignore();
        }
        cin.getline(inv_names[i],20);
    }
}
void chit2::showInvDetails()
{
    cout<<"\n\nInvestor Details :\n-----------------------\n";
    cout<<"Investor ID\tInvestor Name\n";
    for(int i=0;i<inv_choice;i++)
    {
            cout<<i+1<<"\t\t"<<inv_names[i]<<endl;
    }
    cout<<"Enter the file name(with extension) to store the investor details : ";
    cin>>fname;
}
void chit2::bid()
{
   int bidder_id, bid_amount, bidder_amount,continue_choice,minimum,bids[50],bidders[50],bid_winner=1,k,x,num_of_bidders,dip_choice,lucky_dip_id;
    float inv_amount;
    while(present_month<=num_months)
    {

        cout<<"\n\nBid Details for Month "<<present_month<<":\n-------------------------"<<endl;
        k=0;
        cout<<"Are there any investors interested in bidding?\n";
        cout<<"1.Yes\t2.No :::";
        cin>>x;
        if(x==1)
        {
            cout<<"Enter the number of investors interested in bidding:";
            cin>>num_of_bidders;
            cout<<"\n***** Make sure to avoid the investors who have already won the bidding!!! *****\n";
            cout<<"Enter the ID numbers of investors interested in bidding:";
            for(int i=0;i<num_of_bidders;i++)
            {
                cin>>bidders[i];
            }

            for(int i=0;i<num_of_bidders;i++)
            {
                cout<<"\nEnter the bid amount of investor "<<bidders[i]<<" :";
                cin>>bids[i];
                if((chit_value-bids[i])<=org_comission)
                {
                    cout<<"Bid amount should be less than:"<<chit_value-org_comission<<endl;
                }
                else if(bids[i]>chit_value)
                {
                    cout<<"Bid amount cannot be greater than chit value :"<<chit_value<<endl;
                }


            }
             minimum=bids[0];
            bid_winner=bidders[0];
            for(k=1;k<num_of_bidders;k++)
            {
                if(bids[k]<minimum)
                   {

                    minimum=bids[k];
                    bid_winner=bidders[k];
                   }
            }
            bid_amount=minimum;
        }

         else
        {
            dip_choice=0;
            while(dip_choice!=2)
            {


                cout<<"\nLUCKY DIP\n";
                bid_amount=chit_value*0.9;
                cout<<"\nIn this lucky dip the bid value is fixed to "<<bid_amount;
                srand(time(0));
                lucky_dip_id=(rand()%inv_choice)+1;
                cout<<"\n\nID number "<<lucky_dip_id<<" :"<<inv_names[lucky_dip_id-1]<<" have won the lucky dip!!!";
                cout<<"\n\nEnter 1.    If ID:"<<lucky_dip_id<<" have already won bidding! \n\nEnter 2.    If ID:"<<lucky_dip_id<<" is a New winner!\n\nEnter your choice:";
                cin>>dip_choice;
            }
            bid_winner=lucky_dip_id;
        }
        finalIDs[finall]=bid_winner;
        finalBids[finall]=bid_amount;
        finall++;

        cout<<"\n---------------------------------------------------------------------------------------\n";
        cout<<"\nBid amount is :"<<bid_amount;
        cout<<"\n\nBidder ID :"<<bid_winner;
        cout<<"\n\nBidder : "<<inv_names[bid_winner-1]<<endl;
        bidder_amount=bid_amount;
        cout<<"\nAmount to be given to bidder : Rs."<<bidder_amount<<endl;
        inv_amount=monthly_pay_amount-(((chit_value-bidder_amount)-org_comission)/(inv_choice));
        cout<<"\nAmount to be paid by the other investors : Rs."<<inv_amount<<endl;
        cout<<"\nOrganizer commission is :"<<org_comission;
        cout<<"\n---------------------------------------------------------------------------------------\n";
        ofstream out_id2,out_name2,out_amt_to_investor2;
        out_id2.open(fname,ios::app);
        //out_name2.open("names2.txt",ios::app);
        //out_amt_to_investor2.open("amounts2.txt",ios::app);
        out_id2<<bid_winner<<endl;
        out_id2<<inv_names[bid_winner-1]<<endl;
        out_id2<<bidder_amount<<endl;
        out_id2.close();
        out_name2.close();
        out_amt_to_investor2.close();


        int month;
        ifstream in_id2,in_name2,in_amt_to_investor2;
        in_id2.open(fname);
        //in_name2.open("names2.txt");
        //in_amt_to_investor2.open("amounts2.txt");
        cout<<"CHIT DETAILS:\n---------------------------------------------------------------------------------------";
        cout<<"\n\nMONTH:\t     INVESTOR ID:\t      INVESTOR NAME:\t     AMOUNT TO INVESTOR:\n";
        cout<<"---------------------------------------------------------------------------------------";
            for(int i=0;i<present_month;i++)
            {
                in_id2>>id[i];
                in_id2>>name[i];
                in_id2>>amount[i];
                cout<<endl<<endl<<i+1<<"\t\t"<<id[i]<<"\t\t\t"<<name[i]<<"\t\t\t"<<amount[i];

            }
            in_id2.close();
            in_name2.close();
            in_amt_to_investor2.close();
        cout<<"\n\n\n********** END OF MONTH:"<<present_month<<" **********\n\n\n";
        present_month++;
    }
    }


int main()
{
    int ch;
    while(ch!=3)
    {
        cout<<"\n1.Highest bid chit\t2.Lowest bid chit\t3.Exit";
        cout<<"\nEnter your choice:";
        cin>>ch;



        if(ch==1)
        {


            chit1 person1;
            person1.getChitDetails();
            person1.inv_choiceInput();
            person1.chitDescription();
            person1.getInvDetails();
            person1.showInvDetails();
            person1.bid();
            cout<<"\n\n\t\t\t***** END OF CHIT *****\n\n";
           // person1.finalDetails();


        }
        else if(ch==2)
        {
            chit2 person2;
            person2.getChitDetails();
            person2.inv_choiceInput();
            person2.chitDescription();
            person2.getInvDetails();
            person2.showInvDetails();
            person2.bid();
            cout<<"\n\n\t\t\t***** END OF CHIT *****\n\n";
           // person2.finalDetails();
        }

    }

    return 0;
}




