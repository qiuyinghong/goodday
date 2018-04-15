public class ReturnTest
{
	public static void main(String[] args)
	{
		for(int i=0;i<3;i++)
		{
			System.out.println("i的值是"+i);
			if(i==1)
			{
				return;
			}
			System.out.println("return后的输出语句");
		}
	}
}