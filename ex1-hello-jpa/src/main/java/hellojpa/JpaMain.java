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
            // 비영속
            Member member = new Member(150L, "A");
            // 영속
            em.persist(member);

            Member member1 = em.find(Member.class, member.getId());
            member1.setName("ByeA");

            List<Member> result = em.createQuery("select m from Member m", Member.class)
                    .getResultList();

            for (Member m : result) {
                System.out.println(m);
            }

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
