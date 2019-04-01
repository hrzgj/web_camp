package ������;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;  
     
public class counter {      
    private Stack<Character> priStack = new Stack<>();// ������ջ      
    private Stack<Double> numStack = new Stack<>();// ������ջ      
      
         
    public StringBuilder priToNum(String str) 
    {
    	int k=0;
		StringBuilder s=new StringBuilder(50);//�������׺���ʽ
		for(int i=0;i<str.length();i++)
		{
			char c=str.charAt(i);//ȡ����׺���ʽ
			
			if(c>='0'&&c<='9'||c=='.')
			{
				s.append(c);
				continue;
			}
			if(c<'0'||c>'9')
			{
				s.append(' ');
			}
			
			switch (c) 
			{
			//pop��ջ��Ԫ�أ�ֱ��ջ�ף�ջ�գ���pop�õ���һ��'('���ٽ���+����-��ջ
			case '+':
			case '-':
				if(str.charAt(i+1)=='+'||str.charAt(i+1)=='-')
				{
					if(c=='-'&&str.charAt(i+1)=='-'||c=='+'&&str.charAt(i+1)=='+')
						break;
					else
						k++;
					break;
				}
				if(k%2==0)
					c='+';
				else
					c='-';
				if(priStack.isEmpty())//��ջֱ����ջ
				{
					
					priStack.push(c);
				}
				else
				{
					char ch=priStack.peek();
					if(ch=='(')
					{	
						priStack.push(ch);
						priStack.push(c);
					}
					else
					{
						while(!(priStack.isEmpty()))
						{
							char st=priStack.pop();
							s.append(ch);
						}
						priStack.push(c);
					}
				}
				break;
			//�����ǰ��׺Ԫ��Ϊ'*'��'/'��'('��ֱ��push�������ջ
			case '*':
			case '/':
			case '(':
				priStack.push(c);
				break;
			//�����ǰ��׺Ԫ��Ϊ')'��������pop��ջ���������������������׺���ʽβ�ˣ�ֱ��pop�õ�����һ��'('��ֹͣ
			case ')':
				char ch =priStack.pop();
				while(ch!='(')
				{
					s.append(ch);
					ch=priStack.pop();
				}
				break;
			}
			
		}
		while(!priStack.isEmpty())
		{
			char ch=priStack.pop();
			s.append(ch);
		}
		
		return s;
    }
    
    public double cal(StringBuilder str) throws Exception
    {
    	System.out.println(str);
    	StringBuilder sb=new StringBuilder(20);
    	for(int i=0;i<str.length();i++)
    	{
    		int k=0;
    		double num1,num2;
    		char c=str.charAt(i);
    		while(c=='.'||( c>='0'&&c<='9' ) )
    		{
    			
    			sb.append(c);
    			int j=i;
    			if(j>=str.length())
    				break;
    			c=str.charAt(++j);
    			i=j--;
    			k++;
    		}
    		
    		if(k!=0)
    		{
    			
    			numStack.push(Double.parseDouble(sb.toString()));
    			sb.delete(0,k);
    			
    		}
    		switch (c) 
    		{
    		
			case '+':
				num1=numStack.pop();
	    		num2=numStack.pop();
	    		numStack.push(num1+num2);
	    		break;
			case '-':
				num1=numStack.pop();
	    		num2=numStack.pop();
	    		numStack.push(num1-num2);
				break;
			case '*':
				num1=numStack.pop();
	    		num2=numStack.pop();
	    		numStack.push(num1*num2);
	    		break;
			case '/':
				num1=numStack.pop();
	    		num2=numStack.pop();
	    		if(num2==0)
	    		{
	    			throw new Exception("����������Ϊ0");
	    		}
	    		numStack.push(num1/num2);
	    		break;
			}
    	}
    	return numStack.pop();
    }
              
        
      
    public static void main(String args[]) throws Exception {      
        counter operate = new counter();    
        BufferedReader buf =new BufferedReader(new InputStreamReader(System.in));
        String t=buf.readLine();
        
        StringBuilder s=operate.priToNum(t);
        System.out.println(s);
        System.out.println(operate.cal(s));      
    }      
}      