#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<queue>
#include<fstream>
#include<sstream>
#include<time.h>
using namespace std;
#define INF 0x3f3f3f3f// for dijkstra algo
typedef pair<int, int> iPair;
vector<string> areas(10);

//FUNCTION TO DISPLAY THE UPPER CONSTANT SCREEN TO GIVE A DESIGN TO THE CONSOLE SCREEN.
void upper()//TO BE USED BY ALL THE CLASSES
{
    system("cls");//CLEARS THE SCREEN
    cout<<endl<<endl;
    for(int i=0;i<200;i++)
        cout<<"*";
    cout<<endl;
    for(int j=0;j<10;j++)
        cout<<"\t";
    cout<<"ZOLO FLIGHTS"<<endl;//DISPLAYS THE HOTEL NAME WITH A DESIGNED PATTERN ON EACH CONSOLE SCREEN
    for(int i=0;i<200;i++)
        cout<<"*";
    cout<<endl<<endl;
}

//USING DELAY FUNCTION TO PAUSE THE OUTPUT SCREEN FOR FEW SECONDS(AS WILL BE MENTIONED INSIDE ITS PARAMETERS).
void delay(int number_of_seconds)//FUNCTION CAN BE USED BY ANY CLASSES FORMED DURING THE PROGRAM
{
  // Converting time into milli_seconds
  int milli_seconds = 1000 * number_of_seconds;
   // Storing start time
  clock_t start_time = clock();
  // looping till required time is not achieved
  while (clock() <start_time + milli_seconds);
}//END OF DELAY FUNCTION

typedef struct trip
{
    int pickup,drop,flighttype,price,time;
    string flightno,pilot_name,flight_name;
}trip;
typedef struct flight
{
    int id;
    char flightno[9];
    int pickup;
    char pilot_name[6];
    int drop;
    char flight_name[6];
    int flight_status; //Enter only 1 or 0. 1 for flight is not available, 0 for flight is available
    int avg_rating,earnings;
    int noofbookings;
}flight;
//THE FIRST PAGE TO APPEAR AS WE RUN THE PROGRAM
void frontpage()
{
    for(int i=0;i<200;i++)
            cout<<"*";
        cout<<endl;
        for(int i=0;i<15;i++)
        {
            cout<<"*";
            for(int j=0;j<199;j++)
                cout<<" ";
            cout<<"*"<<endl;
        }
        cout<<"*";
        for(int j=0;j<10;j++)
            cout<<"\t";
        cout<<" FLIGHT REPLICATION MODEL SYSTEM";
        for(int i=0;i<12;i++)
            cout<<"\t";
        cout<<"*"<<endl;
        for(int i=0;i<6;i++)
        {
            cout<<"*";
            for(int j=0;j<199;j++)
                cout<<" ";
            cout<<"*"<<endl;
        }
        cout<<"*";
        for(int j=0;j<10;j++)
            cout<<"\t";
        cout<<"    WELCOME TO ZOLO FLIGHTS";//NAME OF THE FLIGHT APPLICATION INTRODUCED
        for(int i=0;i<12;i++)
            cout<<"\t";
        cout<<"*"<<endl;
        for(int i=0;i<10;i++)
        {
            cout<<"*";
            for(int j=0;j<199;j++)
                cout<<" ";
            cout<<"*"<<endl;
        }
        for(int i=0;i<200;i++)
            cout<<"*";
        cout<<endl;
        delay(3);//PAUSE THE CONSOLE SCREEN FOR 3 SECONDS BEFORE PROCEEDING
        system("pause");//PAUSE THE SCREEN UNTIL ANY KEY IS PRESSED
        system("cls");
}
int noofflights;//stores total number of flights

//ALL INFORMATION ABOUT ADMIN OBJECT
class admin
{
    string password,correct_password,email;
public:
    flight ob[20];
    flight hash_table[15];
    admin()
    {
        email="admin";
        //password="admin123";
        correct_password="admin123";
    }
    int admin_login()
    {
        int f=0;
        string username;
        do
        {
            upper();
            for(int j=0;j<9;j++)
                cout<<"\t";
            cout<<"********ADMIN LOGIN*********"<<endl<<endl;
            cout<<"Enter Email: ";
            cin>>username;
            cout<<"Enter Password: ";
            cin>>password;
            if(password==correct_password && username==email)
            {
                system("cls");
                upper();
                cout<<endl<<"Logged in Successfully!"<<endl;
                delay(3);
                system("cls");
                f=1;
            }
            else
            {
                system("cls");
                upper();
                cout<<endl<<"Wrong credentials entered. Please login again!"<<endl;
                system("pause");
                system("cls");
                f=0;
            }
        }while(f!=1);
        return f;
    }
    void change_password()
    {
        string pass,pas1;
        int f=0;
        delay(3);
        do
        {
             upper();
            for(int j=0;j<9;j++)
                cout<<"\t";
            cout<<"********ADMIN LOGIN*********"<<endl<<endl;
            cout<<"Enter new password: ";
            cin>>pass;
            cout<<"Confirm new password: ";
            cin>>pas1;
            if(pass==pas1)
            {
                password=pas1;
                correct_password=pas1;
                cout<<endl<<"Password changed successfully!"<<endl;
                delay(3);
                f=1;
            }
            else
            {
                upper();
                for(int j=0;j<9;j++)
                    cout<<"\t";
                cout<<"********ADMIN LOGIN*********"<<endl<<endl;
                cout<<"Entered passwords do not match! Enter new password again."<<endl;
                system("pause");
            }
        }while(f!=1);
    }
    void pilot_earnings(int i,int x)
    {
        ob[i].earnings=ob[i].earnings+x;
    }
    void add_flight()
    {
        upper();
        for(int j=0;j<9;j++)
            cout<<"\t";
        cout<<"********ADMIN LOGIN*********"<<endl<<endl;
        flight c;
        cout<<"Enter flight number: ";
        cin>>c.flightno;
        cin.clear();
        cout<<"Enter flight booking status: ";
        cin>>c.flight_status;
        cin.clear();
        cout<<"Enter pilot_name: ";
        cin>>c.pilot_name;
        cin.clear();
        cout<<"Enter flight's current pickup: ";
        cin>>c.pickup;
        cin.clear();
        cout<<"Enter flight name: ";
        cin>>c.flight_name;
        cin.clear();
        cout<<"Enter flight's current drop: ";
        cin>>c.drop;
        cin.clear();
        c.avg_rating=5;
        cout<<"Enter flight's earnings till now: ";
        cin>>c.earnings;
        cin.clear();
        cout<<"Enter flight's total no. of booking with us till now: ";
        cin>>c.noofbookings;
        cin.clear();
        c.id=((c.flightno[5]-'0')*1000) + ((c.flightno[6]-'0')*100) + ((c.flightno[7]-'0')*10) + ((c.flightno[8]-'0'));
        ob[noofflights]=c;
        noofflights=noofflights+1;
    }
    void showPilotRatings();
    void update_rating(int rate,int index);
    void flights_detail();
    void delete_flight();
};
admin a1;
void user_menu(int f);
void insertbyhash(flight ob)
{
    int index=(ob.id%13);
    if(a1.hash_table[index].id!=-1)
    {
        a1.hash_table[index]=ob;
    }
    else
    {
        while(a1.hash_table[index].id==-1 && index<15)
        {
            index++;
            if(index==15)
                index=0;
        }
        a1.hash_table[index]=ob;
    }
}
int search_flight(int num)
{
    int counter=0;
    int i=num%13;
    if(a1.hash_table[i].id==num)
    {
        return i;
    }
    else
    {
        while(a1.hash_table[i].id!=num && i<15)
        {
            i++;
            if(i==15)
            {
                i=0;
            }
            counter++;
            if(counter==15)
            {
                break;
            }
        }
        if(counter<15)
        {
           return i;
        }
        else
        {
            return -1;
        }
    }
    if(i<noofflights)
    {
        return i;
    }
    return -1;
}


//REST FUNCTIONS OF ADMIN CLASS
void admin:: flights_detail()
{
    upper();
    for(int j=0;j<9;j++)
        cout<<"\t";
    cout<<"********ADMIN LOGIN*********"<<endl<<endl;
        for(int i=0;i<noofflights;i++)
        {
            cout<<"Flight's ID: "<<a1.ob[i].id<<endl;
            cout<<"Flight number: "<<a1.ob[i].flightno<<endl;
            cout<<"Flight booking status: "<<a1.ob[i].flight_status<<endl;
            cout<<"Pilot_name: "<<a1.ob[i].pilot_name<<endl;
            cout<<"flight's current pickup: "<<a1.ob[i].pickup<<endl;
            cout<<"Flight name: "<<a1.ob[i].flight_name<<endl;
            cout<<"flight's current drop: "<<a1.ob[i].drop<<endl;
            cout<<"Avg_rating: "<<a1.ob[i].avg_rating<<endl;
            cout<<"flight's earnings till now: "<<a1.ob[i].earnings<<endl;
            cout<<"flight's total no. of booking with us till now: "<<a1.ob[i].noofbookings<<endl;
            cout<<endl<<endl;
        }
        for(int i=0;i<200;i++)
            cout<<"*";
        cout<<endl;
        system("pause");
}
void admin:: delete_flight()
{
        upper();
        for(int j=0;j<9;j++)
            cout<<"\t";
        cout<<"********ADMIN LOGIN*********"<<endl<<endl;
        int num;
        cout<<"Enter the flight Id of the flight you want to deregister: ";
        cin>>num;
        int i=search_flight(num);
        if(i!=-1)
        {
            flight tmp;
            tmp=a1.ob[i];
            a1.ob[i]=a1.ob[noofflights-1];
            a1.ob[noofflights-1]=tmp;
            cout<<"\nFlight is deleted from our services!";
            delay(3);
            noofflights--;
        }
        else
        {
            cout<<"Flight not found!";
            delay(3);
            system("cls");
        }
}
void admin::showPilotRatings()
{
         upper();
        for(int j=0;j<9;j++)
            cout<<"\t";
        cout<<"********ADMIN LOGIN*********"<<endl<<endl;
        for(int i=0;i<noofflights;i++)
        {
            cout<<"Pilot_name: "<<a1.ob[i].pilot_name<<endl;
            cout<<"Avg_rating: "<<a1.ob[i].avg_rating<<endl;
            cout<<"flight's earnings till now: "<<a1.ob[i].earnings<<endl;
            cout<<endl<<endl;
        }
        for(int i=0;i<200;i++)
            cout<<"*";
        cout<<endl;
        system("pause");
}
void admin:: update_rating(int rate,int index)
{
        a1.ob[index].avg_rating=(a1.ob[index].avg_rating+rate)/a1.ob[index].noofbookings;
}

//ALL INFORMATION ABOUT USER OBJECT
class user
{
    string mob,password,correct_password,name,email;
    char gender;
    int pickup,drop,flight_type,fare,pilot_rating;
    bool flight_status;
    vector<trip> t;
    flight ob;
public:
    user()
    {
        email="user1";
        //password="user123";
        correct_password="user123";
    }
   int login()
   {
       int f=0;
       string username;
       do
        {
            upper();
            for(int j=0;j<9;j++)
                cout<<"\t";
            cout<<"*********USER LOGIN*********"<<endl<<endl;
            cout<<"Enter Email: ";
            cin>>username;
            cout<<"Enter Password: ";
            cin>>password;
            if(password==correct_password && flight_status==0 && username==email)
            {
                cout<<"Logged in Successfully!"<<endl;
                for(int i=0;i<200;i++)
                    cout<<"*";
                cout<<endl;
                delay(3);
                user_menu(1);
                f=1;
            }
            else
            {
                cout<<"Wrong credentials entered! Please login again."<<endl;
                system("pause");
                f=0;
            }
        }while(f!=1);
        return f;
    }
    void signup()
    {
        int f=0;
        stringstream ss;
        do
        {
            upper();
            for(int j=0;j<9;j++)
                cout<<"\t";
            cout<<"*********USER SIGNUP*********"<<endl<<endl;
            fflush(stdin);
            cout<<"Enter your Name: ";
            getline(cin,name);
            cout<<"Enter email-id: ";
            cin>>email;
            cout<<"Enter Mobile no.: ";
            cin>>mob;
            cout<<"Enter your gender[M/F]: ";
            cin>>gender;
            cout<<"Enter your password: ";
            cin>>password;
            cout<<"Confirm your password: ";
            cin>>correct_password;
            if(password==correct_password)
            {
                f=1;
                login();
            }
            else
            {
                f=0;
                cout<<"Entered passwords do not match please fill the form again!"<<endl;
                system("pause");
            }
        }while(f!=1);
    }
    void change_pass()
    {
        string pass,pass1;
        int f=0;
        do
        {
            upper();
            for(int j=0;j<9;j++)
                cout<<"\t";
            cout<<"*********USER LOGIN*********"<<endl<<endl;
            cout<<"Enter a new password: ";
            cin>>pass;
            cout<<"Confirm new password: ";
            cin>>pass1;
            if(pass==pass1)
            {
                cout<<"Password is changed successfully!"<<endl;
                password=pass;
                correct_password=pass;
                for(int i=0;i<200;i++)
                    cout<<"*";
                delay(3);
                f=1;
            }
            else
            {
                f=0;
                cout<<"Entered passwords do not match! Enter a new password again."<<endl;
                system("pause");
            }
        }while(f!=1);
    }
    void trip_history()
    {
        upper();
        for(int j=0;j<9;j++)
            cout<<"\t";
        cout<<"*********USER LOGIN*********"<<endl<<endl;
        if(t.size()==0)
        {
            cout<<"You haven't had any trip with our services yet! ";
        }
        else
        {
            int si=t.size();
            for(int i=0;i<si;i++)
            {
                cout<<"Trip number: "<<i+1<<endl;
                cout<<"Flight name and number: "<<t[i].flight_name<<t[i].flightno<<endl;
                cout<<"Pilot name: "<<t[i].pilot_name<<endl;
                cout<<"Pickup location: "<<areas[(t[i].pickup)-1]<<endl;
                cout<<"Drop location: "<<areas[(t[i].drop)-1]<<endl;
                cout<<"Fare: Rs. "<<t[i].price<<".00"<<endl;
                cout<<endl<<endl;
            }
        }
        for(int i=0;i<200;i++)
            cout<<"*";
        cout<<endl;
        system("pause");
    }
    void trip_details()
    {
        upper();
        for(int j=0;j<9;j++)
            cout<<"\t";
        cout<<"********TRIP DETAILS********"<<endl<<endl;
        int x=t.size()-1;
        cout<<"Flight name: "<<t[x].flight_name<<endl;
        cout<<"Flight number: "<<t[x].flightno<<endl;
        cout<<"Pilot name: "<<t[x].pilot_name<<endl;
        cout<<"\nPickup location: "<<areas[(t[x].pickup)-1]<<endl;
        cout<<"Drop location: "<<areas[(t[x].drop)-1]<<endl;
        cout<<"Fare: Rs."<<t[x].price<<".00"<<endl;
        for(int i=0;i<200;i++)
            cout<<"*";
        cout<<endl;
        system("pause");
    }
    void getPilotRating(int c)
    {
        upper();
        for(int j=0;j<9;j++)
            cout<<"\t";
        cout<<"*********USER LOGIN*********"<<endl<<endl;
        cout<<"Enter how many stars you want to give[1/2/3/4/5]: ";
        cin>>pilot_rating;
        a1.update_rating(pilot_rating,c);
        cout<<"Thank you for rating the pilot!"<<endl;
        for(int i=0;i<200;i++)
            cout<<"*";
        cout<<endl;
        system("pause");
    }
    void book_flight();
    void book_later();
};
user u1;
//THIS CLASS REPRESENTS A DIRECTED GRAPH USING ADJANCENCY LIST REPRESENTATIONS
class Graph
{
    int V;    // No. of vertices
    list< pair<int, int> > *adj;    // In a weighted graph, we need to store vertex and weight pair for every edge
public:
    Graph(int n)//constructor
    {
        //allocates memory for adjacency list
        V=n;
        adj=new list<iPair> [n];
    }  // Constructor
    void addEdge(int u, int v, int w)// function to add an edge to graph
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    int shortestPath(int src,int dest)// Prints shortest paths from src to all other vertices
    {
        priority_queue< iPair, vector <iPair> , greater<iPair> > pq; // Create a priority queue to store vertices that are being preprocessed.
        vector<int> dist(V, INF); // Create a vector for distances and initialize all distances as infinite (INF)
        pq.push(make_pair(0, src));  // Insert source itself in priority queue and initialize its distance as 0.
        dist[src] = 0;
        while (!pq.empty()) // Looping till priority queue becomes empty (or all distances are not finalized)
        {
           // The first vertex in pair is the minimum distance vertex, extract it from priority queue.
           // vertex label is stored in second of pair (it has to be done this way to keep the vertices
           // sorted distance (distance must be first item in pair)
           int u = pq.top().second;
           pq.pop();
           list< pair<int, int> >::iterator i; // 'i' is used to get all adjacent vertices of a vertex
           for (i = adj[u].begin(); i != adj[u].end(); ++i)
            {
                int v = (*i).first;
                // Get vertex label and weight of current adjacent of u.
                int weight = (*i).second;
                if (dist[v] > dist[u] + weight)  //  If there is shorted path to v through u.
                {
                    dist[v] = dist[u] + weight; // Updating distance of v
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
        return dist[dest];
    }
};
Graph g(10);
void heapify(flight arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l].avg_rating > arr[largest].avg_rating)
        largest = l;
    if (r < n && arr[r].avg_rating > arr[largest].avg_rating)
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void tripheapify(vector<trip> arr, int i)
{
    int parent=(i-1)/2;
    while(parent!=0 && arr[parent].time>arr[i].time)
    {
        trip tmp;
        tmp=arr[parent];
        arr[parent]=arr[i];
        arr[i]=tmp;
        i=parent;
        parent=(i-1)/2;
    }
}
void heapSort(flight arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i=n-1; i>=0; i--)
    {

        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void sort_by_rating()
{
     heapSort(a1.ob,10);
}
int allocate_flight(int start,int endp)
{
    sort_by_rating();
    for(int i=0;i<10;i++)
    {
        if(a1.ob[i].drop==start && a1.ob[i].flight_status==0)
        {
            a1.ob[i].pickup=start;
            a1.ob[i].drop=endp;
            a1.ob[i].noofbookings+=1;
            return i;
        }
    }
    return -1;
}
void user:: book_flight()
{
        upper();
        for(int j=0;j<9;j++)
            cout<<"\t";
        cout<<"*********USER LOGIN*********"<<endl<<endl;
        int dist;
        char confirmation;
        cout<<"You can book a flight between following areas:- "<<endl;
        int si1=areas.size();
        for(int i=0;i<si1;i++)
        {
            cout<<i+1<<"-> "<<areas[i]<<endl;
        }
        cout<<"Enter your choice of pickup location: ";
        cin>>pickup;
        cout<<"Enter your choice of drop location: ";
        cin>>drop;
        cout<<endl<<"You can book a flight of following types:- "<<endl;
        cout<<"1-> ECO"<<endl<<"2-> BUSINESS"<<endl<<"3-> PRIME"<<endl<<"4-> Luxury"<<endl;
        cout<<"Enter your choice of flight type: ";
        cin>>flight_type;
        dist=g.shortestPath(pickup-1,drop-1);
        cout<<"Shortest path between "<<areas[pickup-1]<<" and "<<areas[drop-1]<<" is of "<<dist<<" kms."<<endl;
        fare=(7 + flight_type)*dist;
        cout<<"Fare of your trip would be Rs."<<fare<<".00"<<endl<<"Are you sure you want to book a flight?[Y/N]: ";
        cin>>confirmation;
        if(confirmation=='Y'||confirmation=='y')
        {
            int c;
            c=allocate_flight(pickup,drop);
            if(c!=-1)
            {
                cout<<endl<<"You are allocated "<<a1.ob[c].flightno<<"! Enjoy your ride!"<<endl;
                for(int i=0;i<200;i++)
                    cout<<"*";
                cout<<endl;
                system("pause");
                flight_status=1;
                trip tmp;
                tmp.flightno=a1.ob[c].flightno;
                tmp.flight_name=a1.ob[c].flight_name;
                tmp.flighttype=flight_type;
                tmp.pilot_name=a1.ob[c].pilot_name;
                tmp.drop=drop;
                tmp.pickup=pickup;
                tmp.price=fare;
                tmp.time=0;
                t.push_back(tmp);
                a1.pilot_earnings(c,fare);
                cout<<"You are on your way!"<<endl;
                for(int i=0;i<200;i++)
                    cout<<"*";
                cout<<endl;
                system("pause");
                getPilotRating(c);
            }
            else
            {
                cout<<endl<<"Sorry! No flights available right now !! "<<endl;
                for(int i=0;i<200;i++)
                    cout<<"*";
                cout<<endl;
                system("pause");
            }
        }
}
void user:: book_later()
{
        char confirmation;
        int time,dist;
        upper();
        for(int j=0;j<9;j++)
            cout<<"\t";
        cout<<"*********USER LOGIN*********"<<endl<<endl;
        cout<<"Enter after what time you want to take the ride [in hrs]: ";
        cin>>time;
        cout<<"You can book a flight between following areas:- "<<endl;
        int si2=areas.size();
        for(int i=0;i<si2;i++)
        {
            cout<<i+1<<"-> "<<areas[i]<<endl;
        }
        cout<<"Enter your choice of pickup location : ";
        cin>>pickup;
        cout<<"Enter your choice of drop location : ";
        cin>>drop;
        cout<<endl<<"You can book a flight of following types:- "<<endl;
        cout<<"1-> ECO"<<endl<<"2-> BUSINESS"<<endl<<"3-> PRIME"<<endl<<"4-> Luxury"<<endl;
        cout<<"Enter your choice of flight type : ";
        cin>>flight_type;
        dist=g.shortestPath(pickup-1,drop-1);
        cout<<"Shortest path between "<<areas[pickup-1]<<" and "<<areas[drop-1]<<" is of "<<dist<<" kms."<<endl;
        fare=(7 + flight_type)*dist;
        cout<<"Fare of your trip would be Rs."<<fare<<".00!"<<endl<<"Are you sure you want to book a flight?[Y/N]: ";
        cin>>confirmation;
        if(confirmation=='Y'||confirmation=='y')
        {
            int c;
            c=allocate_flight(pickup,drop);
            if(c!=-1)
            {
                cout<<"You are allocated "<<a1.ob[c].flightno<<"! Enjoy your ride!"<<endl;
                for(int i=0;i<200;i++)
                    cout<<"*";
                cout<<endl;
                system("pause");
                flight_status=1;
                trip tmp;
                tmp.flightno=a1.ob[c].flightno;
                tmp.flight_name=a1.ob[c].flight_name;
                tmp.flighttype=flight_type;
                tmp.pilot_name=a1.ob[c].pilot_name;
                tmp.drop=drop;
                tmp.pickup=pickup;
                tmp.price=fare;
                tmp.time=time;
                t.push_back(tmp);
                tripheapify(t,t.size());
                cout<<"You will reach your destination in desired time!"<<endl;
                for(int i=0;i<200;i++)
                    cout<<"*";
                cout<<endl;
                system("pause");
                a1.pilot_earnings(c,fare);
            }
        }
}
void admin_menu(int choice,int f)
{
    int ch1;
    if(choice==3 && f==1)
    {
        int opp=0;
        do
        {
           upper();
           for(int j=0;j<9;j++)
              cout<<"\t";
          cout<<"**********OPTIONS******"<<endl<<endl;
          cout<<"1-> CHANGE PASSWORD"<<endl;
          cout<<"2-> DISPLAY THE FLIGHTS WHICH ARE ALREADY ADDED WITH OUR SERVICES"<<endl;
          cout<<"3-> ADD ANOTHER FLIGHT"<<endl;
          cout<<"4-> DELETE A FLIGHT"<<endl;
          cout<<"5-> SHOW ALL PILOTS' RATINGS"<<endl;
          cout<<"6-> UPDATE ANY PILOT'S RATING"<<endl;
          cout<<"7-> EXIT"<<endl;
          cout<<"Enter your choice: ";
          cin>>ch1;
          switch(ch1)
          {
    case 1:
        a1.change_password();
        a1.admin_login();
        opp=0;
        break;
    case 2:
        a1.flights_detail();
        opp=0;
        break;
    case 3:
        a1.add_flight();
        opp=0;
        break;
    case 4:
        a1.delete_flight();
        opp=0;
        break;
    case 5:
        a1.showPilotRatings();
        opp=0;
        break;
    case 6:
        int f,rate;
        int cbn;
        upper();
        for(int j=0;j<9;j++)
            cout<<"\t";
        cout<<"********ADMIN LOGIN*********"<<endl<<endl;
        cout<<"Enter the flight id whose pilot's rating you want to update: ";
        cin>>cbn;
        cin.clear();
        cout<<"Enter how much you want to rate him[1/2/3/4/5]: ";
        cin>>rate;
        f=search_flight(cbn);
        a1.update_rating(rate,f);
        cout<<endl<<"UPDATED."<<endl;
        delay(3);
        opp=0;
        break;
    case 7:
        for(int i=0;i<200;i++)
            cout<<"*";
        delay(3);
        opp=1;
        break;
    default:
        cout<<"Wrong option selected. Please select again."<<endl;
        delay(4);
        opp=0;
        break;
      }
    }while(opp==0);
  }
}

void user_menu(int f)
{
    int ch1;
    if(f==1)
    {
        int pop=0;
        do
        {
          upper();
          for(int j=0;j<9;j++)
            cout<<"\t";
          cout<<"*********USER LOGIN*********"<<endl<<endl;
          cout<<"1-> CHANGE PASSWORD"<<endl;
          cout<<"2-> BOOK A FLIGHT FOR NOW"<<endl;
          cout<<"3-> BOOK A FLIGHT FOR LATER"<<endl;
          cout<<"4-> TRIP HISTORY"<<endl;
          cout<<"5-> PREVIOUS TRIP DETAILS"<<endl;
          cout<<"6-> EXIT"<<endl;
          cout<<"Enter your choice: ";
          cin>>ch1;
          switch(ch1)
          {
    case 1:
        pop=1;
        u1.change_pass();
        u1.login();
        break;
    case 2:
        pop=1;
        u1.book_flight();
        break;
    case 3:
        pop=1;
        u1.book_later();
        break;
    case 4:
        pop=1;
        u1.trip_history();
        break;
    case 5:
        pop=1;
        u1.trip_details();
        break;
    case 6:
        pop=0;
        for(int i=0;i<200;i++)
            cout<<"*";
        cout<<endl;
        delay(3);
        break;
    default:
        pop=1;
        cout<<"WRONG CHOICE ENTERED. PLEASE SELECT AGAIN."<<endl;
        for(int i=0;i<200;i++)
            cout<<"*";
        cout<<endl;
        delay(3);
        break;
        }
     }while(pop!=0);
   }
}
void End()
{
       system("cls");
       for(int i=0;i<200;i++)
            cout<<"*";
        cout<<endl;
        for(int i=0;i<15;i++)
        {
            cout<<"*";
            for(int j=0;j<199;j++)
                cout<<" ";
            cout<<"*"<<endl;
        }
        cout<<"*";
        for(int j=0;j<10;j++)
            cout<<"\t";
        cout<<"FLIGHT REPLICATION MODEL SYSTEM";
        for(int i=0;i<12;i++)
            cout<<"\t";
        cout<<"*"<<endl;
        for(int i=0;i<6;i++)
        {
            cout<<"*";
            for(int j=0;j<199;j++)
                cout<<" ";
            cout<<"*"<<endl;
        }
        cout<<"*";
        for(int j=0;j<9;j++)
            cout<<"\t";
        cout<<"THANK YOU FOR USING THE SYSTEM OF ZOLO FLIGHTS.HAVE A NICE DAY.";
        for(int i=0;i<9;i++)
            cout<<"\t";
        cout<<"*"<<endl;
        for(int i=0;i<10;i++)
        {
            cout<<"*";
            for(int j=0;j<199;j++)
                cout<<" ";
            cout<<"*"<<endl;
        }
        for(int i=0;i<200;i++)
            cout<<"*";
        cout<<endl;
        cout<<"\t\t\t\t\t\t\t~A PROJECT BY: PARTH NARANG,MEGHNA AGARWAL, HARDIK SINGH AND SIDHI GROVER."<<endl;
}
int main()
{
    frontpage();
    upper();
    int f;
    areas[0]="DELHI";
    areas[1]="KOLKATA";
    areas[2]="BHOPAL";
    areas[3]="CHENNAI";
    areas[4]="JAIPUR";
    areas[5]="BANGALORE";
    areas[6]="AHMEDABAD";
    areas[7]="DISPUR";
    areas[8]="GANGTOK";
    areas[9]="LUCKNOW";
    g.addEdge(0, 1, 19);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    g.addEdge(9, 5, 30);
    g.addEdge(9, 3, 25);
    int choice,i;
    fstream fil,fil2;
    fil.open("flightdatabase.txt",ios::in);
    i=0;
    flight c;
    char ch;
    while(!fil.eof())
    {
        fil.read((char*) &c,sizeof(c));
        a1.ob[i]=c;
        insertbyhash(c);
        i++;
    }
    noofflights=i;
    fil.close();
    int opt=1;
    do
    {
    upper();
    for(int j=0;j<9;j++)
        cout<<"\t";
    cout<<"*********MAIN MENU**********"<<endl<<endl;
    cout<<"1-> USER LOGIN"<<endl;
    cout<<"2-> USER SIGNUP"<<endl;
    cout<<"3-> ADMIN LOGIN"<<endl;
    cout<<"4-> EXIT"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        {
            f=u1.login();
            opt=1;
            break;
        }
    case 2:
        {
            user u2;
            u2.signup();
            opt=1;
            break;
        }
    case 3:
        {
            f=a1.admin_login();
            admin_menu(choice,f);
            opt=1;
            break;
        }
    case 4:
        opt=0;
        break;
    default:
        opt=1;
        cout<<"WRONG CHOICE ENTERED. PLEASE ENTER AGAIN."<<endl;
        delay(4);
        break;
    }
    }while(opt!=0);
    cout<<endl;
    for(int i=0;i<200;i++)
        cout<<"*";
    cout<<endl;
    system("pause");
    fil.open("flightdata1.txt",ios::out);
    for(int i=0;i<noofflights;i++)
    {
        flight c=a1.ob[i];
        fil.write((char*) &c,sizeof(c));
    }
    fil.close();
    fil.open("flightdata1.txt",ios::in);
    fil2.open("flightdatabase.txt",ios::out);
    while (!fil.eof())
    {
         fil.get(ch);
         fil2<<ch;
    }
    fil2.close();
    fil.close();
    areas.clear();
    End();
    return 0;
}
