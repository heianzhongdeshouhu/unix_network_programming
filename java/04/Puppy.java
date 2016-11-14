public class Puppy {
    int puppyAge;
    public Puppy(String name) {
    // this constructor has only one parameter: name
    System.out.println("the puppy's name is: " + name );
    }

    public void setAge( int age ) {
        puppyAge = age;
    }

    public int getAge() {
        System.out.println("the puppy's age is: " + puppyAge);
        return puppyAge;
    }

    public static void main(String []args) {
        /* create object  */
        Puppy myPuppy = new Puppy( "tommy" );

        myPuppy.setAge(2);
        
        myPuppy.getAge();

        System.out.println("variable is: " + myPuppy.puppyAge);
    }
}
