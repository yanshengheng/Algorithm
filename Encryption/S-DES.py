#from array import *
plaintext="10011101"
mainkey="0111111101"

class Plaintext:
        def InitPermutation(self,plaintext):
		p1 = plaintext[0]
		p2 = plaintext[1]
		p3 = plaintext[2]
		p4 = plaintext[3]
		p5 = plaintext[4]
		p6 = plaintext[5]
		p7 = plaintext[6]
		p8 = plaintext[7]
		#Konwn rule:
		P = p2+p6+p3+p1+p4+p8+p5+p7
		return P
	def EslashP(self,right_part):
		p1 = right_part[0]
		p2 = right_part[1]
		p3 = right_part[2]
		p4 = right_part[3]
		P = p4+p1+p2+p3+p2+p3+p4+p1
		return P
	#odd_number divide 2 lose fraction
	def Left_pt(self,plaintext):
		left_part = len(plaintext)/2
		return plaintext[0:left_part]
	def Right_pt(self,plaintext):
		right_part = len(plaintext)/2
		return plaintext[right_part:len(plaintext)]
	def index2d(self,left_pt):
		#get row
		if left_pt[0] == "0":
			if left_pt[3] == "0":
				row = 0
			else:
				row = 1
		else:
			if left_pt[3] == "0":
				row = 2
			else:
				row = 3
		#get column
		if left_pt[1] == "0":
                        if left_pt[2] == "0":
				column = 0
			else:
				column = 1
		else:
			if left_pt[2] == "0":
				column = 2
			else:
				column = 3
		return [row,column]
	def S0(self,left_pt):
		s0 = [ [1,0,3,2],\
			 	[3,2,1,0],\
	   			[0,2,1,3],\
				 [3,1,3,2]]

		index = self.index2d(left_pt)
		L2 = s0[index[0]][index[1]]
		if L2 == 0:
			L = "00"
		elif L2 ==1:
			L ="01"
		elif L2 ==2:
			L ="10"
		else:
			L = "11"
		return L

	def S1(self,right_pt):
		s1 = [ [0,1,2,3],\
				[2,0,1,3],\
	   			[3,0,1,0],\
 				[2,1,0,3] ]	 
		
		index = self.index2d(right_pt)
		L2 = s1[index[0]][index[1]]
		if L2 == 0:
			L = "00"
		elif L2 ==1:
			L ="01"
		elif L2 ==2:
			L ="10"
		else:
			L = "11"
		return L

	def XOR(self,a,b):
		P = ""
		for i in range(0,len(a)):
			if a[i] != b[i]:
				P = P+"1"
			else:
				P = P+"0"
		return P
	def P4(slef,plaintext):
		p1 = plaintext[0]
		p2 = plaintext[1]
		p3 = plaintext[2]
		p4 = plaintext[3]
		P = p2+p4+p3+p1
		return P
        def InitPermutConverse(self,plaintext):
                p1 = plaintext[0]
                p2 = plaintext[1]
                p3 = plaintext[2]
                p4 = plaintext[3]
                p5 = plaintext[4]
                p6 = plaintext[5]
                p7 = plaintext[6]
                p8 = plaintext[7]
                P = p4+p1+p3+p5+p7+p2+p8+p6
                return P
class KEY:
	def P10(self,key):
		k1 = key[0]
		k2 = key[1]
		k3 = key[2]
		k4 = key[3]
		k5 = key[4]
		k6 = key[5]
		k7 = key[6]
		k8 = key[7]
		k9 = key[8]
		k10 = key[9]
		#Given Condition:
		K = k3+k5+k2+k7+k4+k10+k1+k9+k8+k6
		return K
	def P8(self,key):
		k1 = key[0]
		k2 = key[1]
		k3 = key[2]
		k4 = key[3]
		k5 = key[4]
		k6 = key[5]
		k7 = key[6]
		k8 = key[7]
		k9 = key[8]
		k10 = key[9]
		K = k6+k3+k7+k4+k8+k5+k10+k9
		return K
	def mv1bit(self,key):
		k1 = key[0]
		k2 = key[1]
		k3 = key[2]
		k4 = key[3]
		k5 = key[4]
		k6 = key[5]
		k7 = key[6]
		k8 = key[7]
		k9 = key[8]
		k10 = key[9]
		K = k2+k3+k4+k5+k1 + k7+k8+k9+k10+k6
		return K
	def mv2bit(self,key):
		k1 = key[0]
		k2 = key[1]
		k3 = key[2]
		k4 = key[3]
		k5 = key[4]
		k6 = key[5]
		k7 = key[6]
		k8 = key[7]
		k9 = key[8]
		k10 = key[9]
		K = k3+k4+k5+k1+k2 + k8+k9+k10+k6+k7
		return K
if __name__=="__main__":
	pt = Plaintext()
	key = KEY()
	#plaintext = "01000001"
	#mainkey = "1010000010"

	#get k1 and k2
	m1 = key.P10(mainkey)
	m2 = key.mv1bit(m1)
	m3 = key.mv2bit(m2)
	k1 = key.P8(m2)
	k2 = key.P8(m3)
	print "K1= "+k1
	print "K2= "+k2

	#encrypt plaintext
	p1 = pt.InitPermutation(plaintext)
	l1 = pt.Left_pt(p1)
	r1 = pt.Right_pt(p1)
	ep_r1 = pt.EslashP(r1)
	p2 = pt.XOR(ep_r1,k1)
	print "P2= "+p2

	#s0 s1 box encryptino
	l2 = pt.Left_pt(p2)
	r2 = pt.Right_pt(p2)
	l3 = pt.S0(l2) +  pt.S1(r2)
	print "L3= " + l3
	l4 = pt.P4(l3)
	print "L4= " +l4
	l5 = pt.XOR(l1,l4)
	print "L5= " +l5
	p3 =  l5 + r1
        p4 =  r1 + l5
	print "P3= " +p3
        print "P4= " +p4
        l6 = r1
        r6 = l5
	ep_r6 = pt.EslashP(l5)
	print "e/p(r6)= " + ep_r6
        p5 = pt.XOR(ep_r6,k2)
        print "P5 = " + p5
        l7 = pt.Left_pt(p5)
        r7 = pt.Right_pt(p5)
        l8 = pt.S0(l7)+pt.S1(r7)
        print "L8= " + l8
        l9 = pt.P4(l8)
        print "L9= " + l9
        l10 = pt.XOR(l6,l9)
        print "L10= " + l10
        p6 = l10 + r6
        print "P6= " +p6
        p7 = pt.InitPermutConverse(p6)
        print "C= " +p7
