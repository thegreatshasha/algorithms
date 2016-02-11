var op=['+','-','*','/'];

function evalu(a,target,pos,prev)
{	console.log(prev, pos, a.length)
	if(pos == a.length) {
		console.log("p", prev, "t", target)
		if(prev == target){
			console.log("milla ")
            		true;
		}
		return false;
	}
	for(var i=0; i<4; i++) {
		var res = 0;
		var ch = op[i];
		if(ch == '+') {
			res = prev + a[pos];
		} else if(ch == '-') {
			res = prev - a[pos];
		} else if(ch == '*') {
			res = prev * a[pos];
		} else {
			res = prev / a[pos];
		}
		if( evalu(a,target,pos+1,res ) )
			return true;
	}
	return false;
}

console.log(evalu([6,5,4,3,2], 32, 0, 0))