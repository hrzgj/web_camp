package 计算器;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;  
     
public class counter {      
    private Stack<Character> priStack = new Stack<>();// 操作符栈      
    private Stack<Double> numStack = new Stack<>();// 操作数栈      
      
         
    public StringBuilder priToNum(String str) 
    {
    	int k=0;
		StringBuilder s=new StringBuilder(50);//用来存后缀表达式
		for(int i=0;i<str.length();i++)
		{
			char c=str.charAt(i);//取出中缀表达式
			
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
			//pop出栈顶元素，直至栈底（栈空）或pop得到了一个'('，再将此+或者-入栈
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
				if(priStack.isEmpty())//空栈直接入栈
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
			//如果当前中缀元素为'*'，'/'或'('，直接push入操作符栈
			case '*':
			case '/':
			case '(':
				priStack.push(c);
				break;
			//如果当前中缀元素为')'，则依次pop出栈顶操作符，“输出”到后缀表达式尾端，直至pop得到的是一个'('才停止
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
	    			throw new Exception("被除数不能为0");
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