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
            Member member = new Member();
            member.setId(1L);
            member.setName("HelloA");
            em.persist(member);

            Member member1 = em.find(Member.class, 1L);
            member1.setName("ByeA");

            List<Member> result = em.createQuery("select m from Member m", Member.class)
                    .getResultList();

            for (Member m : result) {
                System.out.println(m);
            }

            tx.commit();
        } catch (Exception e) {
            tx.rollback();
        } finally {
            em.close();
        }

        emf.close();
    }
}
