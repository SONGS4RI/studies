package hellojpa;

import java.util.List;

import jakarta.persistence.*;

public class JpaMain {

    public static void main(String[] args) {

        EntityManagerFactory emf = Persistence.createEntityManagerFactory("hello");
        EntityManager em = emf.createEntityManager();
        //code
        EntityTransaction tx = em.getTransaction();
        tx.begin();
        try {
            // 영속
            Member member = new Member(200L, "member200");
            em.persist(member);

            Member member1 = em.find(Member.class, 200L);
            em.detach(member1);
            member1.setName("changed");

            em.flush();
            System.out.println("-----------------");

            tx.commit();
            // 이때 모든 쿼리가 날아간다.
        } catch (Exception e) {
            tx.rollback();
        } finally {
            em.close();
        }

        emf.close();
    }
}
