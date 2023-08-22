import java.util.Iterator;

public class IteratorInJava{
	public class Object{
		private String info;

		public Object(String info){
			this.info = info;
		}

		public String getInfo(){
			return info;
		}
	}

	public interface Colletion{
		public Iterator createIterator();
	}

	public class ObjectColletion implements Colletion{
		private Object[] objects;
		private int last = 0;

		public ObjectColletion(int size){
			objects = new Object[size];
		}
		public Object getObject(int index){
			return objects[index];
		}
		public int getLength(){
			return last;
		}
		public void appendObject(Object object){
			if(last < objects.length){
				this.objects[last++] = object;
			}
			else{
				System.out.println("Collection is fulled");
			}
		}
		@Override
			public Iterator createIterator(){
				return new ObjectColletionIterator(this);
			}
	}

	public class ObjectColletionIterator implements Iterator<Object>{
		private ObjectColletion objectColletion;
		private int index = 0;

		public ObjectColletionIterator(ObjectColletion objectColletion){
			this.objectColletion = objectColletion;
		}
		@Override
			public boolean hasNext(){
				return index < objectColletion.getLength();
			}
		@Override
			public Object next(){
				Object object = objectColletion.getObject(index++);
				return object;
			}
	}

	public static void main(String args[]){
		ObjectColletion objectColletion = new ObjectColletion(5);
		
		Object object1 = new Object("object1");
		Object object2 = new Object("object2");
		Object object3 = new Object("object3");
		Object object4 = new Object("object4");
		Object object5 = new Object("object5");

		objectColletion.appendObject(object1);	
		objectColletion.appendObject(object2);	
		objectColletion.appendObject(object3);	
		objectColletion.appendObject(object4);	
		objectColletion.appendObject(object5);	

		Iterator iter = objectColletion.createIterator();
		while(iter.hasNext()){
			Object object = (Object) iter.next();
			System.out.println(Object.getInfo());
		}
	}
}
