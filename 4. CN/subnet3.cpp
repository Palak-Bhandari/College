#include <iostream>
#include <math.h>
#include <sstream>
#include <string.h>
using namespace std;
int getHostBits(string ip_class){
    if(ip_class=="A")
        return 24;
    else if(ip_class=="B")
        return 16;
    else return 8;
}
int getNetworkBits(string ip_class){
    if(ip_class=="A")
        return 8;
    else if(ip_class=="B")
        return 16;
    else return 24;
}
int binaryToDecimal(string n){
    string num = n;
    int dec_value = 0;
    int base = 1;
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}
string getClass(string ip){
    string delimiter = ".";
    size_t pos = 0;
    string token;
    while((pos = ip.find(delimiter)) !=std::string::npos){
        token = ip.substr(0, pos);
        if (std::stoi(token) < 128)
            return "A";
        else if (std::stoi(token) < 192)
            return "B";
        else if (std::stoi(token) < 224)
            return "C";
        else if (std::stoi(token) < 240)
            return "D";
    }
}
int main(){
    int pc, i=0;
    string ip_class;
    cout<<"Enter the number of PCs in the network : ";
    cin>>pc;
    string ip="";
    cout<<"\nEnter the IP address : ";
    cin>>ip;
    ip_class = getClass(ip);
    cout<<"\nThe Class of the IP address : "<<ip_class;
    int host_bits = getHostBits(ip_class);
    for(i=0;i<=10;i++){
        if(pow(2,i) >=pc)
            break;
    }
    int net_bits = i;   
    int total_ip_in_each_network = pow(2,i);    
    int Network_bits = host_bits - net_bits;
    int size_of_network = pow(2,Network_bits);
    cout<<"\nSize of Network : "<<size_of_network;
    cout<<"\nTotal IPs in each Network : "<<total_ip_in_each_network;
    string mask="", subnet="", total_mask="";
    int total_net_bits = getNetworkBits(ip_class) + Network_bits;
    cout<<"\nTotal Network bits : "<<total_net_bits;
    int max_ips = pow(2, host_bits);
    cout << "\nMaximum IPs we can utilize in class [" << ip_class << "] : " << max_ips << endl;
    for(int i=1; i<=4; i++){
        for(int j=1; j<=8; j++){
            if(total_mask.length()<total_net_bits){
                mask = mask + "1";
                total_mask +=  "1";
            }
            else{
                mask = mask + "0";
                total_mask +=  "0";
            }
        }
        subnet += to_string(binaryToDecimal(mask)) + ".";
        mask = "";
    }
    cout<<"\nSubnet Mask = : "<<subnet;
    cout<<endl<<endl;
    return 0;
}
