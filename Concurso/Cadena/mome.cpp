memcpy( FFF+5 , FFF, 20  )
memcpy( FFF , FFF +5, 20  )
memcpy( FFF , AAA, 20  )

memcpy( FFF , AAA, 0  )
memcpy( FFF , FFF, 20  )
memcpy( FFF , FFF, 0  )

memcpy( FFF , AAA, -4  )

void memcpy(void *dest, const void *src, size_t len)
{
	

	bool case1 = false;
	for (int i = 0; i < len; ++i)
		if (src +i == dest)
		{
			case1= true;
			break;
		}



	if (  inrange(dest - src, 0,len)  )
		//second kind
	else if (  inrange( src - dest, 0,len)  )
		//fisrt kind


	if (case1)
		for (int i = len - 1; i >= 0; --i)
			*(des + i)  =  *(src + i);
	else
		for (int i = 0; i < len; ++i)
			*(des + i)  =  *(src + i);
			
	
}

s------------d++------ +++

d----------s-------+++++++++++