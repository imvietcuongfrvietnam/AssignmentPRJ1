char* reverseWords(char* s) {
    int k = strlen(s);
    char *res = (char*)malloc(sizeof(char) * k);
    //Cat dau chuoi va cuoi chuoi s
    int start = 0;
    int finish = k-1;
    while(s[start] == ' ' && start<=finish){
    	start++;
	}
	while(s[finish] == ' ' && start<=finish){
    	finish--;
	}
	int _finish = finish;
	while(start<=finish){
		while(s[finish] != ' ' && start<=finish){
			finish--;
		}
		
	}
    
}
