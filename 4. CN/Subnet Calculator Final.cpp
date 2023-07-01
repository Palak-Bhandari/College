#include<bits/stdc++.h>
using namespace std;
vector<int> bits_convert(int n){
	vector<int>bits;
	if(n>=128){
		bits.push_back(1);
		n-=128;
	}
	else bits.push_back(0);
	if(n>=64){
		bits.push_back(1);
		n-=64;
	}
	else bits.push_back(0);
	if(n>=32){
		bits.push_back(1);
		n-=32;
	}
	else bits.push_back(0);
	if(n>=16){
		bits.push_back(1);
		n-=16;
	}
	else bits.push_back(0);
	if(n>=8){
		bits.push_back(1);
		n-=8;
	}
	else bits.push_back(0);
	if(n>=4){
		bits.push_back(1);
		n-=4;
	}
	else bits.push_back(0);
	if(n>=2){
		bits.push_back(1);
		n-=2;
	}
	else bits.push_back(0);
	if(n>=1){
		bits.push_back(1);
		n-=1;
	}
	else bits.push_back(0);
	return bits;
}
string find_class_ip(int n){
	if(n>=1 && n<=126) return "Class A";
	else if(n>=128 && n<=191) return "Class B";
	else if(n>=192 && n<=223) return "Class C";
	else return "Invalid IP";
}
string find_class_sm(int a,int b,int c,int d){
	if(a==255 && b!=255 && c!=255 && d!=255) return "Class A";
	else if(a==255 && b==255 && c!=255 && d!=255) return "Class B";
	else if(a==255 && b==255 && c==255 && d!=255)  return "Class C";
}
void find_network_id(int a, int b,int c,int d){
	if(find_class_ip(a) == "Class A"){
		cout<<"Network ID is: "<<a<<"."<<"0.0.0"<<endl;
	}
	else if(find_class_ip(a) == "Class B"){
		cout<<"Network ID is: "<<a<<"."<<b<<".0.0"<<endl;
	}
	else if(find_class_ip(a) == "Class C"){
		cout<<"Network ID is: "<<a<<"."<<b<<"."<<c<<".0"<<endl;
	}
}
int count_1(vector<int>a){
	int c=0;
	for(int i=0;i<a.size();i++) if(a[i]==1) c++;
	return c;
}
int main(){
	string ip,sm;
	cout<<"Enter IP address: ";
	cin>>ip;
	cout<<"Enter Subnet Mask: ";
	cin>>sm;
	string a="",b="",c="",d="";
	string s1="",s2="",s3="",s4="";
	int cnt=0,no_hosts,u_hosts,no_sn;
	for(int i=0;i<ip.length();i++){
		if(ip[i] == '.') cnt++;
		else if(cnt==0) a+=ip[i];
		else if(cnt==1) b+=ip[i];
		else if(cnt==2) c+=ip[i];
		else if(cnt==3) d+=ip[i];	
	}
	cnt=0;
	for(int i=0;i<sm.length();i++){
		if(sm[i] == '.') cnt++;
		else if(cnt==0) s1+=sm[i];
		else if(cnt==1) s2+=sm[i];
		else if(cnt==2) s3+=sm[i];
		else if(cnt==3) s4+=sm[i];
	}
	
	int a1,b1,c1,d1;
	stringstream bit_a(a);
	bit_a>>a1;
	stringstream bit_b(b);
	bit_b>>b1;
	stringstream bit_c(c);
	bit_c>>c1;
	stringstream bit_d(d);
	bit_d>>d1;
	
	int s01,s02,s03,s04;
	stringstream bit_s1(s1);
	bit_s1>>s01;
	stringstream bit_s2(s2);
	bit_s2>>s02;
	stringstream bit_s3(s3);
	bit_s3>>s03;
	stringstream bit_s4(s4);
	bit_s4>>s04;
    string sm_cls = find_class_sm(s01,s02,s03,s04);
    cout<<"\nClass of subnet mask: "<<sm_cls;
    
	vector<int>bits_s1 = bits_convert(s01);
	vector<int>bits_s2 = bits_convert(s02);
	vector<int>bits_s3 = bits_convert(s03);
	vector<int>bits_s4 = bits_convert(s04);
	
	int count0,count1,cidr;
	cout<<"\nClass of the IP address is: "<<find_class_ip(a1)<<endl;
	find_network_id(a1,b1,c1,d1);
	if(find_class_sm(s01,s02,s03,s04) == "Class A"){
		count1 = count_1(bits_s2);
		count0 = 24 - count1;
		cidr = count1+8;
	}
	else if(find_class_sm(s01,s02,s03,s04) == "Class B"){
		count1 = count_1(bits_s3);
		count0 = 16 - count1;
		cidr = count1+16;
	}
	else if(find_class_sm(s01,s02,s03,s04) == "Class C"){
		count1 = count_1(bits_s4);
		count0 = 8 - count1;
		cidr = 24+count1;
	}
	no_hosts = pow(2,count0);
	no_sn = pow(2,count1);
	u_hosts = no_hosts-2;
	cout<<"\nTotal no of hosts: "<<no_hosts;
	cout<<"\nTotal usable hosts: "<<u_hosts;
	cout<<"\nTotal subnets: "<<no_sn;
	cout<<"\nCIDR: "<<ip<<"/"<<cidr;
	
	cout<<"\n\nNetwork ID \t\t Usable Host Range \t\t Broadcast ID\n";
	if(find_class_sm(s01,s02,s03,s04) == "Class A"){
		int b = 255 - s02;
		for(int i=0;i<no_sn;i++){
			cout<<a1<<"."<<(b+1)*i<<".0.0 \t ";
			cout<<a1<<"."<<(b+1)*i<<".0.1  -  ";
			cout<<a1<<"."<<b*(i+1)+i<<".255.254 \t ";
			cout<<a1<<"."<<b*(i+1)+i<<".255.255 \t\n";
		}
	}
	else if(find_class_sm(s01,s02,s03,s04) == "Class B"){
		int c = 255 - s03;
		for(int i=0;i<no_sn;i++){
			cout<<a1<<"."<<b1<<"."<<(c+1)*i<<".0 \t ";
			cout<<a1<<"."<<b1<<"."<<(c+1)*i<<".1  -  ";
			cout<<a1<<"."<<b1<<"."<<c*(i+1)+i<<".254 \t ";
			cout<<a1<<"."<<b1<<"."<<c*(i+1)+i<<".255 \t\n";
		}
	}
	else if(find_class_sm(s01,s02,s03,s04) == "Class C"){
		for(int i=0;i<no_sn;i++){
			cout<<a1<<"."<<b1<<"."<<c1<<"."<<i*no_hosts<<" \t ";
			cout<<a1<<"."<<b1<<"."<<c1<<"."<<(i*no_hosts)+1<<"  -  ";
			cout<<a1<<"."<<b1<<"."<<c1<<"."<<((i+1)*no_hosts)-2<<" \t ";
			cout<<a1<<"."<<b1<<"."<<c1<<"."<<((i+1)*no_hosts)-1<<" \t\n";
		}
	}
	return 0;
}  
