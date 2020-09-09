sub LT_0 {
	my $first_cent = $_[0] ;
	my $first_type = $_[1] ;
	my $zushu = $_[2] ;
	my $Pd_0 = 1; 
	for ( my $lin_i = 1 ; $lin_i <= $first_type ; $lin_i ++ ) {
		$Pd_0 = $Pd_0 * $cent_type[$d_1[$first_cent][$lin_i]] ;
	}
	if ( $Pd_0 == 0 ) {
		for ( my $lin_i = 1 ; $lin_i <= $first_type ; $lin_i ++ ) {
			if ( $cent_type[$d_1[$first_cent][$lin_i]] == 0 ) {
				$cent_type[$d_1[$first_cent][$lin_i]] = $zushu ;
				&LT_0( $d_1[$first_cent][$lin_i] , $type[$d_1[$first_cent][$lin_i]] , $cent_type[$d_1[$first_cent][$lin_i]] ) ;
			}
		}
	}
}

open (FI,"<F.txt") ;
open FP,'+> MCG.txt';

while (<FI>){
	push @fi ,[split] ;
}

$i = 0 ;

foreach my $a(@fi) {
	$i ++ ;
	$cent_0[$i] = $a -> [0] ;
	$type[$cent_0[$i]] = $a -> [1] ;
	$d_1[$cent_0[$i]][1] = $a -> [2] ;
	$d_1[$cent_0[$i]][2] = $a -> [3] ;
	$d_1[$cent_0[$i]][3] = $a -> [4] ;
	$d_1[$cent_0[$i]][4] = $a -> [5] ;
	$d_1[$cent_0[$i]][5] = $a -> [6] ;
	$d_1[$cent_0[$i]][6] = $a -> [7] ;
	$d_1[$cent_0[$i]][7] = $a -> [8] ;
	$d_1[$cent_0[$i]][8] = $a -> [9] ;
	$d_1[$cent_0[$i]][9] = $a -> [10] ;
	$d_1[$cent_0[$i]][10] = $a -> [11] ;
	$d_1[$cent_0[$i]][11] = $a -> [12] ;
	$d_1[$cent_0[$i]][12] = $a -> [13] ;
	$d_1[$cent_0[$i]][13] = $a -> [14] ;
	$d_1[$cent_0[$i]][14] = $a -> [15] ;
	$d_1[$cent_0[$i]][15] = $a -> [16] ;
	$cent_type[$cent_0[$i]] = 0 ;
}

$zhushu = 1 ;
$jishu_zhu[$zhushu] = 0 ;

for ( $j = 1 ; $j <= $i ; $j ++ ) {
	if ( $cent_type[$cent_0[$j]] == 0 ) {
		&LT_0( $cent_0[$j] , $type[$cent_0[$j]] , $zhushu );
		$zhushu ++
	}
}

for (my $fff = 1 ; $fff <= $zhushu ; $fff ++ ) {
	for ( $j = 1 ; $j <= $i ; $j ++ ) {
		if ( $cent_type[$cent_0[$j]] == $fff ) {
			$jishu_zhu[$fff] ++ ;
		}
	}
}
$max = $jishu_zhu[$zhushu] ;
$max_i = $zhushu ;

for (my $fff = 1 ; $fff < $zhushu ; $fff ++ ) {
	if ( $jishu_zhu[$fff] > $max ) {
		$max = $jishu_zhu[$fff] ;
		$max_i = $fff ;
	}
}
print FP "$max | ";
for ( $j = 1 ; $j <= $i ; $j ++ ) {
	if ( $cent_type[$cent_0[$j]] == $max_i ) {
		print FP " $cent_0[$j] ";
	}
}
print FP "\n";