#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//各乐音的频率，分别为：低音，中音高音，倍高音
int N[4][7]=
{
131,147,165,175,196,220,247,
262,294,330,349,392,440,494,
523,587,659,698,784,880,988,
1047,1175,1319,1397,1568,1760,1976
};
int pow2(int n){
	int ret=1;
	while(n--){
		ret*=2;
	}
	return ret;
}
//根据字符串播放音乐
void sing(char *str,int bpm){
	int len=strlen(str);
	if(len%3!=0){
		printf("String is wrong!!\n");
		return;
	}
	int i;
	int lower,tone,val;
	for(i=0;i<len;i++){
		lower=str[i*3]-'0';
		tone=(str[i*3+1]-'A'+5)%7;
		val=(60000*4/(bpm))/pow2(str[i*3+2]-'0') ;

		if(lower<0 || lower > 2 || tone<0|| val<0){
			printf("Error at %d\n",i);
			return;
		}
		if(tone>=0 && tone<=6)
			_beep(N[lower][tone],val);
		else{
			_sleep(val);
		}

	}
}

int main(void)
{
	char *song=
	"0G30G30A20G21C20B1"
	"0G30G30A20G21D21C1"
	"0G30G31G21E21C20B20A2"
	"1F31F31E21C21D21C1";
	sing(song,130);
    return 0;
}
