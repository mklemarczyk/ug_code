package sets;

import java.util.ArrayList;

public class SetDir {
	ArrayList<SetNode> dict;

	public SetDir() {
		this.dict = new ArrayList<SetNode>();
	}

	public void makeSet(int num) {
		if (this.dict.size() <= num) {
			this.dict.ensureCapacity(num + 1);
		}
		this.dict.add(num, new SetNode(num));
	}

	public SetNode findSet(int num) {
		SetNode node = this.dict.get(num);
		if (node != null) {
			if (node.parent == node)
				return node;
			else
				return findSet(node.parent.getNumber());
		}
		return null;
	}

	public SetNode compressFindSet(int num) {
		SetNode node = this.dict.get(num);
		if (node != null) {
			if (node.parent != node) {
				node.parent = compressFindSet(node.parent.getNumber());
			}
		}
		return node.parent;
	}

	public SetNode union(SetNode nodeX, SetNode nodeY) {
		if (nodeY.rank > nodeX.rank) {
			nodeX.parent = nodeY;
			return nodeY;
		} else {
			nodeY.parent = nodeX;
			if (nodeX.rank == nodeY.rank) {
				nodeX.rank++;
			}
			return nodeX;
		}
	}

	public void print() {
		for (int i = 0, count = this.dict.size(); i < count; i++) {
			this.dict.get(i).print();
			System.out.println();
		}
	}
}
