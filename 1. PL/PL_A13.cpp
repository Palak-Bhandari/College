#include<iostream>
#include<string.h>
using namespace std;
char temp[20];
void combination(char *str,int r,int index){
	int i;
	for(i=0;i<strlen(str);i++){
		temp[index]=str[i];
		if(index == r-1)
			cout<<temp<<"\t";
		else
			combination(str,r,index+1);
	}
}
int main(){
	int r;
	char str[20];
	cout<<"Enter the string: ";
	cin>>str;
	cout<<"All possible combinations are:-\n";
	for(r=1;r<=strlen(str);r++){
		combination(str,r,0);
	}	
	return 0;
}
/*
Enter the string: star
All possible combinations are:-
s       t       a       r       ss      st      sa      sr      ts      tt      ta      tr      as   
at      aa      ar      rs      rt      ra      rr      sss     sst     ssa     ssr     sts     stt     
sta     str     sas     sat     saa     sar     srs     srt     sra     srr     tss     tst     tsa     
tsr     tts     ttt     tta     ttr     tas     tat     taa     tar     trs     trt     tra     trr     
ass     ast     asa     asr     ats     att     ata     atr     aas     aat     aaa     aar     ars     
art     ara     arr     rss     rst     rsa     rsr     rts     rtt     rta     rtr     ras     rat     
raa     rar     rrs     rrt     rra     rrr     ssss    ssst    sssa    sssr    ssts    sstt    ssta    
sstr    ssas    ssat    ssaa    ssar    ssrs    ssrt    ssra    ssrr    stss    stst    stsa    stsr    
stts    sttt    stta    sttr    stas    stat    staa    star    strs    strt    stra    strr    sass    
sast    sasa    sasr    sats    satt    sata    satr    saas    saat    saaa    saar    sars    sart    
sara    sarr    srss    srst    srsa    srsr    srts    srtt    srta    srtr    sras    srat    sraa    
srar    srrs    srrt    srra    srrr    tsss    tsst    tssa    tssr    tsts    tstt    tsta    tstr    
tsas    tsat    tsaa    tsar    tsrs    tsrt    tsra    tsrr    ttss    ttst    ttsa    ttsr    ttts    
tttt    ttta    tttr    ttas    ttat    ttaa    ttar    ttrs    ttrt    ttra    ttrr    tass    tast    
tasa    tasr    tats    tatt    tata    tatr    taas    taat    taaa    taar    tars    tart    tara    
tarr    trss    trst    trsa    trsr    trts    trtt    trta    trtr    tras    trat    traa    trar    
trrs    trrt    trra    trrr    asss    asst    assa    assr    asts    astt    asta    astr    asas    
asat    asaa    asar    asrs    asrt    asra    asrr    atss    atst    atsa    atsr    atts    attt    
atta    attr    atas    atat    ataa    atar    atrs    atrt    atra    atrr    aass    aast    aasa    
aasr    aats    aatt    aata    aatr    aaas    aaat    aaaa    aaar    aars    aart    aara    aarr    
arss    arst    arsa    arsr    arts    artt    arta    artr    aras    arat    araa    arar    arrs    
arrt    arra    arrr    rsss    rsst    rssa    rssr    rsts    rstt    rsta    rstr    rsas    rsat    
rsaa    rsar    rsrs    rsrt    rsra    rsrr    rtss    rtst    rtsa    rtsr    rtts    rttt    rtta    
rttr    rtas    rtat    rtaa    rtar    rtrs    rtrt    rtra    rtrr    rass    rast    rasa    rasr    
rats    ratt    rata    ratr    raas    raat    raaa    raar    rars    rart    rara    rarr    rrss    
rrst    rrsa    rrsr    rrts    rrtt    rrta    rrtr    rras    rrat    rraa    rrar    rrrs    rrrt    
rrra    rrrr
--------------------------------
Process exited after 10.97 seconds with return value 0
Press any key to continue . . .*/
