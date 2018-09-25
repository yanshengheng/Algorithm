#data structure:
#public_key = { e:num, module:num}
import math
from fractions import gcd

def Encryption(plaintext,public_key): #public key
    m = plaintext**public_key["e"]
    m2 = m / public_key["module"]
    m3 = int(m2) * public_key["module"]
    ciphertext= m - m3
    return int(ciphertext)

def Decryption(ciphertext,private_key):
    m = ciphertext**private_key["d"]
    m2 = m / private_key["module"]
    m3 = int(m2) * private_key["module"]
    plaintext = m - m3
    return plaintext

def GetPrivateKey(public_key,fi):
    g = gcd(public_key["e"],fi)#Totient = fi(n) = p*q
    print "gcg(e,fi)= " + str(g)
    x = (fi - g)/ public_key["e"]
    d = fi - x
    print "private_key= " + str(d)
    return d

if __name__=="__main__":
    p =7
    q =17 #given prime numbers
    plaintext=19
    e = 5

    public_key = { "e":e, "module":p*q}
    d =GetPrivateKey(public_key,(p-1)*(q-1))
    private_key = {"d":d,"module":p*q}

    print Encryption(plaintext,public_key)
