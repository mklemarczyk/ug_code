package sets;

public class SetNode {
	public SetNode parent;
	public int rank;
	private int number;
	
	public SetNode(int num) {
		this.number = num;
		this.parent = this;
		this.rank = 0;
	}

	public int getNumber(){
		return this.number;
	}
	
	public void print(){
		System.out.print(this.number); 
		if(this.parent != this){
			System.out.print(" - ");
			this.parent.print();
		}
	}
}
