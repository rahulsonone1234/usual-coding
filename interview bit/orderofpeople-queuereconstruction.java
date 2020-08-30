public class OrderOfPeoplesHeight {

    public ArrayList<Integer> order(ArrayList<Integer> A, ArrayList<Integer> B) {

        ArrayList<Integer> r = new ArrayList<>();

        TreeMap<Integer,Integer> map = new TreeMap<>();

        for(int i=0;i<A.size();i++){
            map.put(A.get(i), B.get(i));
        }

        while(!map.isEmpty()){

            int height = map.lastKey();
            int taller = map.get(height);

            map.remove(height);

            if(r.size() ==0){
                r.add(height);
            }
            else if(taller == 0){
                r.add(0,height);
            }
            else{
                r.add(taller,height);
            }
        }

        return r;
    }
}
