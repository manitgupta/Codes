
j = 0;
for(i = 0; i < result.size(); i++)
{
	if (i+1 < result.size() && result[i] == result[i+1])
	{
		j++;
	}	
	else
		result[i-j] = result[i];
}
result.resize(i-j);