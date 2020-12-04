


/*************

 Driver program to test below functions
 
int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    Polynomial result;
    switch(choice){
            // Add
        case 1:
            result = first + second;
            result.print();
            break;
            // Subtract
        case 2 :
            result = first - second;
            result.print();
            break;
            // Multiply
        case 3 :
            result = first * second;
            result.print();
            break;
            
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}
****************/

class Polynomial {
        public:
    int *degCoeff;      // Name of your array (Don't change this)
    int capacity;
    // Complete the class
    

    
    Polynomial()
    {
        this -> degCoeff = new int[10] {0};
        this -> capacity = 10;
    }
    
    
    void setCoefficient(int degree , int coefficient)
    {
       
        if(degree<capacity)
        {
            this->degCoeff[degree] = coefficient;
            return ;
        }
        else
        {
            int *array = new int [2*capacity] {0};
            for(int i=0;i<capacity;i++)
                array[i] = this->degCoeff[i];
            this->capacity = 2*capacity;
            this->degCoeff = array;
            
          
            setCoefficient(degree,coefficient);
        }
    }
    
    
    Polynomial operator+(Polynomial const & p) const
    {
        Polynomial pNew;
        int i=0,j=0;
        while(i<this -> capacity && j< p.capacity){
            int deg=i;
            int Coeff = this -> degCoeff[i]+p.degCoeff[j];
            pNew.setCoefficient(deg,Coeff);
            i++;
            j++;
        }
        while(i<capacity){
            pNew.setCoefficient(i,degCoeff[i]);
            i++;
        }
        while(j<p.capacity){
            pNew.setCoefficient(j,p.degCoeff[j]);
            j++;
        }
        return pNew;
    }
    
    
    Polynomial operator-(Polynomial const & p) const
    {
      
        Polynomial pNew;
        int i=0,j=0;
        while(i < this -> capacity && j < p.capacity){
            int deg=i;
            int Coeff = this -> degCoeff[i] - p.degCoeff[j];
            pNew.setCoefficient(deg , Coeff);
            i++;
            j++;
        }
         while(i<capacity){
            pNew.setCoefficient(i,degCoeff[i]);
            i++;
        }
        while(j<p.capacity){
            pNew.setCoefficient(j,(-1 * p.degCoeff[j]));
            j++;
        }
        return pNew;
    }
    
    int getCoeff(int degree)
    {
        if(degree>=capacity)
            return 0;
        else
            return this->degCoeff[degree];
    }
    
  
    int getCoefficient(int degree){
        if(degree >= capacity){
            return 0;
        }
        return degCoeff[degree];
    }
    Polynomial operator*(Polynomial p){
        Polynomial pNew;
        for(int j=0;j<p.capacity;j++){
            for(int i=0;i<capacity;i++){
                int deg = i+j;
                int Coeff = pNew.getCoefficient(deg)+(this->degCoeff[i]*p.degCoeff[j]);
                pNew.setCoefficient(deg,Coeff);
            }
        }
        return pNew;
    }

 
    
    void operator=(Polynomial const &p)
    {
        int *input = new int[p.capacity];
        
        for(int i=0;i<p.capacity;i++)
        {
        	input[i] = p.degCoeff[i];
        }
        this->degCoeff = input;
        //delete []input;
        this->capacity = p.capacity;
         
    }
    
    
    Polynomial(Polynomial const &p)
    {
        int * input = new int[p.capacity];
        
        for(int i=0;i<p.capacity;i++)
        {
        	input[i] = p.degCoeff[i];
        }
        delete [] this->degCoeff;
        this->degCoeff = input;
        this->capacity = p.capacity;
         
    }
    
    
    bool operator==(Polynomial const & p )
    {
        for(int i=0;i<this->capacity;i++)
        {
            if(this->degCoeff[i] != p.degCoeff[i])
                return false;
        }
        return true;
    }
    
    
    
    void print() const
    {
        for(int i=0;i<this->capacity;i++)
        {
            if(this->degCoeff[i]!=0)
            	cout<<this->degCoeff[i]<<"x"<<i<<" ";
        }
        cout<<endl;
    }
    
    
    ~Polynomial(){}
    
};
