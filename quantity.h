#pragma once
#include<string>
#include<map>

class Quantity 
{  
public:
	double val;
	std::string unit ="unknown!";
	Quantity():val(0.){}
	Quantity(const double& v):val(v){}
	Quantity(const double& v, const std::string& u):val(v),unit(u){} 
};

std::ostream& operator<<(std::ostream& output, const Quantity& q)
{       
        if(q.unit == "unknown!")
        {
        	output << q.val;
        }
        
	else
	output <<q.val<<" "<< q.unit;
	
	return output;
}

std::map<std::string, double> metric_prefix = 
{
	{"",1.0e00},
	{"deci", 1.0e-01},  
        {"cent", 1.0e-02},  
        {"milli", 1.0e-03},
        {"micro", 1.0e-06},  
        {"nano", 1.0e-09},  
       	{"pico", 1.0e-12},
        {"femto", 1.0e-15},  
        {"atto", 1.0e-18},  
        {"zepto", 1.0e-21},
        {"yocto", 1.0e-24},        
        {"deca", 1.0e+01},  
        {"hecto", 1.0e+02},  
        {"kilo", 1.0e+03},
        {"mega", 1.0e+06},  
        {"giga", 1.0e+09},  
       	{"tera", 1.0e+12},
        {"peta", 1.0e+15},  
        {"exa", 1.0e+18},  
        {"zetta", 1.0e+21},
        {"yotto", 1.0e+24},    
};
  
Quantity UnitConvert( Quantity q , std::string to_unit)
{    
	Quantity res;
	res.unit = to_unit;
	int count{};
	std::string m="meters";
	std::string g="grams";
	std::string sec="seconds";	
	 
	for(auto it = metric_prefix.begin(); it != metric_prefix.end(); ++it)
	{  
		std::string s;
	        s = it->first;
	        if(to_unit == s+m)       { count=6; break;}
	        else if(to_unit == s+g)  { count=5; break;}
	        else if(to_unit == s+sec){ count=7; break;}   
	}
	        	        
	q.unit.resize(q.unit.size() - count);
	to_unit.resize(to_unit.size() - count);
	        
	auto from = metric_prefix.find(q.unit);
	auto to   = metric_prefix.find(to_unit);
	
        res.val = q.val*( from->second)/(to->second);
	 					
    	return res;
}
