#include <bits/stdc++.h>
using namespace std;
int arreglo[]{0,1,0,2,3,0,5,4,7,0,0,0,11,9,13,8,0,0,17,0,19,0,0,0,23,0,0,0,12,0,29,25,31,0,0,0,22,0,37,18,27,0,41,0,43,0,0,0,47,0,0,0,0,0,53,0,39,49,0,0,59,0,61,32,0,0,0,0,67,0,0,0,71,0,73,0,0,0,45,0,79,0,0,0,83,0,0,0,0,0,89,36,0,50,0,0,77,0,97,0,0,0,101,0,103,0,0,0,107,0,109,0,91,0,113,0,0,0,0,0,95,81,0,0,75,0,82,64,127,0,0,0,131,121,0,0,0,0,137,0,139,0,0,0,119,0,0,0,0,0,149,0,151,0,0,0,125,0,157,0,133,0,106,0,163,0,0,0,167,0,0,98,0,0,173,0,129,0,0,0,179,0,181,169,0,0,122,0,0,0,0,0,191,0,193,72,0,0,197,0,199,0,0,0,134,0,0,0,0,0,116,0,211,0,0,0,187,100,0,0,0,0,146,0,223,0,0,0,227,0,229,0,0,0,233,0,0,0,0,0,239,0,241,0,0,0,0,0,183,0,0,0,251,0,0,128,217,0,257,0,171,0,0,0,263,0,148,0,0,0,269,0,271,0,0,0,0,0,277,0,247,0,281,0,283,0,0,0,253,0,0,0,0,0,293,0,219,0,0,0,152,0,0,0,259,0,202,289,307,0,0,0,311,0,313,0,0,0,317,0,237,0,0,0,265,0,0,0,0,0,218,0,331,0,0,0,299,0,337,0,0,0,245,0,0,0,0,0,347,0,349,0,301,0,353,0,0,0,0,0,359,0,0,162,243,0,0,0,367,0,0,0,305,0,373,0,0,0,212,0,379,361,0,0,383,0,0,0,0,0,389,0,291,0,0,0,262,0,397,242,343,0,401,225,0,0,0,0,335,0,409,0,0,0,274,0,309,0,0,0,419,0,421,0,0,0,0,0,0,0,0,0,431,0,433,0,0,0,0,0,439,0,0,0,443,0,0,0,403,0,449,0,0,0,0,0,407,0,457,0,0,0,461,0,463,200,0,0,467,0,0,0,0,0,314,0,268,0,0,0,479,0,0,0,0,0,0,0,487,0,0,0,491,0,333,0,427,0,0,0,499,0,0,0,503,0,0,0,192,0,509,256,381,0,0,0,0,0,292,0,0,0,521,0,523,0,0,0,473,0,0,0,481,0,0,0,0,0,0,0,493,0,541,0,469,0,369,0,547,338,0,0,411,529,0,0,0,0,557,0,417,0,0,0,563,0,0,0,0,0,569,0,571,0,0,0,527,0,577,0,0,0,386,0,0,0,0,0,587,0,0,0,511,0,593,0,0,0,0,0,599,0,601,0,0,0,0,0,607,0,0,0,505,0,613,0,559,0,617,0,619,0,0,0,515,0,0,0,0,0,356,0,631,0,0,0,422,0,0,0,589,0,641,0,643,0,0,0,647,0,0,0,0,0,653,0,489,0,0,0,659,0,661,0,0,0,0,0,0,0,0,0,611,0,673,0,0,0,677,0,0,0,0,0,683,0,388,0,0,0,458,0,691,0,0,0,519,0,0,0,0,0,701,0,0,0,0,0,0,0,709,0,0,0,404,0,0,0,0,0,719,0,0,0,0,0,482,0,727,0,0,0,507,0,733,0,0,0,0,0,739,441,0,0,743,0,0,0,0,0,0,0,751,0,0,0,697,0,757,0,703,0,761,0,0,0,0,0,713,0,769,0,0,0,773,0,579,0,0,0,531,625,0,0,679,0,0,0,787,0,0,0,731,0,0,0,0,0,797,0,597,0,0,0,0,0,549,0,0,0,809,0,811,0,0,0,737,0,0,288,0,0,821,0,823,0,0,0,827,0,829,0,721,0,554,0,0,0,0,0,839,0,0,0,0,0,562,324,633,0,0,0,566,0,853,392,0,0,857,0,859,0,0,0,863,0,0,0,793,0,0,841,0,0,0,0,0,0,877,0,817,0,881,0,883,0,0,0,887,0,0,0,0,0,0,0,669,0,0,0,745,0,0,0,0,0,0,0,907,0,0,0,911,0,0,0,0,0,0,0,919,578,0,0,614,0,0,0,0,0,929,484,0,0,0,0,699,0,937,0,0,0,941,0,0,0,0,0,947,0,0,0,871,0,953,0,0,0,0,0,899,400,657,0,0,0,548,0,967,0,0,0,971,0,0,0,0,0,977,0,556,0,0,0,983,0,0,0,0,0,0,0,991,961,0,0,662,0,997,0,0,};
int main()
{
	int n, i=0;
	while(cin>>n,n) 
	{
		cout<<"Case "<<++i<<": ";
		if(arreglo[n])	cout<<arreglo[n]<<endl; else cout<<"-1\n";
	}
	return 0;
}