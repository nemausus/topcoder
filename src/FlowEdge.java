/*************************************************************************
 *  Compilation:  javac FlowEdge.java
 *  Execution:    java FlowEdge
 *
 *  Capacitated edge with a flow in a flow network.
 *
 *************************************************************************/

/**
 *  The <tt>FlowEdge</tt> class represents a capacitated edge with a flow
 *  in a digraph.
 *  <p>
 *  For additional documentation, see <a href="/algs4/74or">Section 7.4</a> of
 *  <i>Algorithms, 4th Edition</i> by Robert Sedgewick and Kevin Wayne.
 */


public class FlowEdge {
    private final int v;             // from
    private final int w;             // to 
    private final int capacity;   // capacity
    private int flow;             // flow

    public FlowEdge(int v, int w, int capacity) {
        if (capacity < 0) throw new RuntimeException("Negative edge capacity");
        this.v         = v;
        this.w         = w;
        this.capacity  = capacity;
        this.flow      = 0;
    }

    public FlowEdge(int v, int w, int capacity, int flow) {
        if (capacity < 0) throw new RuntimeException("Negative edge capacity");
        this.v         = v;
        this.w         = w;
        this.capacity  = capacity;
        this.flow      = flow;
    }

    // copy constructor
    public FlowEdge(FlowEdge e) {
        this.v         = e.v;
        this.w         = e.w;
        this.capacity  = e.capacity;
        this.flow      = e.flow;
    }

    // accessor methods
    public int from()         { return v;        }
    public int to()           { return w;        }
    public int capacity()  { return capacity; }
    public int flow()      { return flow;     }


    public int other(int vertex) {
        if      (vertex == v) return w;
        else if (vertex == w) return v;
        else throw new RuntimeException("Illegal endpoint");
    }

    public int residualCapacityTo(int vertex) {
        if      (vertex == v) return flow;
        else if (vertex == w) return capacity - flow;
        else throw new RuntimeException("Illegal endpoint");
    }

    public void addResidualFlowTo(int vertex, int delta) {
        if      (vertex == v) flow -= delta;
        else if (vertex == w) flow += delta;
        else throw new RuntimeException("Illegal endpoint");
    }


    public String toString() {
        return v + "->" + w + " " + flow + "/" + capacity;
    }
}