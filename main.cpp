#include<iostream>
#include<stdio.h>
#include<stdarg.h>
#include<string>


using namespace std;

// Convert String to Integer 
int my_atoi(char *str){
	int result=0; int sign =1;
	//Checking For negative values 
	if(*str=='-')
	{
		sign*=-1;
		str++; 
	}
	for(int i=0;str[i]!='\0';++i)
		result=result*10 + str[i] - '0';
	return result;
}

// From String to Float 
float my_atof(char* str){
	float result=0,factor=1;
	// Checking for Negative Values 
	if(*str=='-')
	{
		factor*=-1;
		str++; 
	}

	for (int i=0;*str!='\0';str++)
	{	
		//Finding a point decimal devide factor by 10
		if ( *str=='.') { i=1; continue;}
		if(i) { factor/=10.0f;} 
		result= result*10.0f +float(*str-'0');
	}

	return result*factor;
}




// Parse a String at a specific Delimeter 
char* my_strtok(char *str,char *delem)
{   char *result=(char *)malloc(sizeof(char)*100); 
	static int position=0;
	if(!str || !delem || str[position]=='\0') 
	{return NULL;}


	//i for indexing the string , j for indexing the delem , k for indexing the result
	int i=position,j=0,k=0;
		
	while(str[i]!='\0')
	{
		j=0;
		while(delem[j]!='\0')
		{
			if(str[i]!=delem[j])
			{
				result[k]=str[i];
			}
			else goto ELSE;
			j++;
		}

	i++;
	k++;
	}
ELSE:
		result[i]='\0';
		position=i+1;
		return result;	 


}
int main () {

char int_number[]="89";
char f_number[]="89.5";
//int result_int=my_atoi(int_number);
//float result_float=my_atof(f_number);
//cout<<result_int<<endl;
//cout<<result_float<<endl;

char str[100]="This--is--a--trial--for--strtok--function--implementation";
char delemiter[]="--";
char *token=my_strtok(str,delemiter);

/*while(token)
	{
		cout<<token<<endl;
		free(str);
		token=my_strtok(NULL,delemiter);

}*/



}



