#include <iostream>
#include <iomanip>
using namespace std;
class Shopping{
	string item[10];
	double price[10];
	int qty[10];
    int count=0;
    double total=0;
    int total_qty=0;
	public:
	void add_item(){
		cout<<"Enter item name: ";
		cin>>item[count];
		cout<<"Enter price: ";
		cin>>price[count];
		cout<<"Enter Quantity: ";
		cin>>qty[count];
		total = total + price[count]*qty[count];
        total_qty = total_qty + qty[count];
        count++;
	}
	void display(){
		int i;
		cout<<endl<<left<<setw(15)<<"Code"<<setw(15)<<"Item"<<setw(15)<<"Quantity"<<setw(15)<<"Price"<<setw(15)<<"Total Price"<<endl;
		for(i=0;i<count;i++){
			cout<<left<<setw(15)<<i+100<<setw(15)<<item[i]<<setw(15)<<qty[i]<<setw(15)<<price[i]<<setw(15)<<qty[i]*price[i]<<endl;
		}
        cout<<endl<<"Grand Total: "<<total;
        cout<<endl<<"Value in Inventory: "<<total_qty<<endl;
	}
	void del_item(){
	    int i;
	    char temp[10];
		cout<<"Enter item name: ";
		cin>>temp;
		for(i=0;i<count;i++){
		    if(item[i]==temp){
		        break;
		    }
		}
        total = total - price[i]*qty[i];
        total_qty = total_qty - qty[i];
		while(i!=count-1){
		    item[i]=item[i+1];
		    item[i+1]="";
		    price[i]=price[i+1];
		    price[i+1]=0;
		    qty[i]=qty[i+1];
		    qty[i+1]=0;
		    i++;
		}
		count--;
	}
};

int main(){
	Shopping onkar;
	int ip=0;
	while(ip!=4){
	cout<<"Shopping Menu: "<<endl;
	cout<<"1. Add Items"<<endl;
	cout<<"2. Display Shopping List"<<endl;
	cout<<"3. Remove Items"<<endl;
	cout<<"4. Exit"<<endl;
	cout<<"Enter Choice: ";
	cin>>ip;
	switch(ip){
		case 1:
			onkar.add_item();
			break;
		case 2:
			onkar.display();
			break;
		case 3:
		    onkar.del_item();
			break;
		case 4:
			break;
		default:
			cout<<"Invalid Option!"<<endl;
			break;
	}		
	}	
	return 0;
}
