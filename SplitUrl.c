#include <bits/stdc++.h>
using namespace std;

char request[] = {"GET / HTTP/1.1 \r\n\
Host: www.tm.com \r\n\
Connection: keep-alive \r\n\
Cache-Control: max-age=0 \r\n\
Upgrade-Insecure-Requests: 1 \r\n\
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/86.0.4240.193 Safari/537.36 \r\n\
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9 \r\n\
Accept-Encoding: gzip, deflate \r\n\
Accept-Language: zh-CN,zh;q=0.9,en;q=0.8 \r\n\
If-None-Match: \"5fbd044b-264\" \r\n\
If-Modified-Since: Tue, 24 Nov 2020 13:02:03 GMT\r\n\r\n" 
} ;

void splitUrl(char * url){
    char ch[] = "172.16.2.107:8080";
    const char *CRLF = "\r\n";
    const char *LF = "\n";
    const char *sep_flag = NULL;
    char *sep = NULL;
    char last[1024];
    sep = strstr(url, CRLF);
    if (NULL == sep){
        sep = strstr(url, LF);
        if (NULL == sep)return;
        else sep_flag = LF;
    }else{
        sep_flag = CRLF;
    }
    char* slash_p = strstr(url, "Host:");   
    int len = abs(slash_p + strlen("Host: ") - url) ;
    cout << len << " " << strlen(slash_p)<< endl;
    sep = strstr(slash_p,sep_flag);
    memcpy(last,sep,strlen(sep) + 1);
    if (slash_p) {
        int len = strlen("Host: ");
        slash_p += len;
        int i;
        for(i = 0;i < strlen(ch);i++){
                slash_p[i] = ch[i];
        }
        slash_p[i] = '\0';
        memcpy(sep,slash_p,strlen(slash_p) + 1);
    }
    url[len] = '\0';
    sprintf(url,"%s%s%s",url,sep,last);
    cout << slash_p << endl;
    return;
}

int main(){
	splitUrl(request);
	printf("%s\n",request);
	return 0;
}