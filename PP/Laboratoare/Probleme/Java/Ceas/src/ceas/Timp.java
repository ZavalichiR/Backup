package ceas;

public class Timp {
	int ore;
	int min;
	int sec;
	
	public Timp()
	{
		ore=0;
		min=0;
		sec=0;
	}
	public Timp(int o,int m,int s)
	{
		ore=o;
		min=m;
		sec=s;
	}
	public void incOre()
	{
		ore++;
		if(ore>23)
		{
			ore=ore-24;
		}
	}
	public void incMin()
	{
		min++;
		if(min>60)
		{
			min=min-60;
			ore++;
		}
	}
	public void incSec()
	{
		sec++;
		if(sec>60)
		{
			sec=sec-60;
			min++;
		}
	}
	public int getOra()
	{
		return ore;
	}
	public int getMin()
	{
		return min;
	}
	public int getSec()
	{
		return sec;
	}
}

