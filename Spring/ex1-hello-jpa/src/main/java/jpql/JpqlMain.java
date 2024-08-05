package jpql;


import jakarta.persistence.*;

import java.util.List;

public class JpqlMain {
	public static void main(String[] args) {
		EntityManagerFactory emf = Persistence.createEntityManagerFactory("hello");
		EntityManager em = emf.createEntityManager();
		//code
		EntityTransaction tx = em.getTransaction();
		tx.begin();
		try {
			Team teamA = new Team();
			teamA.setName("teamA");
			em.persist(teamA);

			Team teamB = new Team();
			teamA.setName("teamB");
			em.persist(teamB);

			Member member1 = new Member();
			member1.setUsername("member1");
			member1.changeTeam(teamA);
			em.persist(member1);

			Member member2 = new Member();
			member2.setUsername("member2");
			member2.changeTeam(teamA);
			em.persist(member2);

			Member member3 = new Member();
			member3.setUsername("member3");
			member3.changeTeam(teamA);
			em.persist(member3);

			// n + 1 문제 야기
			String query1 = "select m from Member m";
			List<Member> result1 = em.createQuery(query1, Member.class).getResultList();
			// 한방 쿼리
			String query2 = "select distinct m from Member m join fetch m.team";
			List<Member> result2 = em.createQuery(query2, Member.class).getResultList();
			// 페치 조인을 사용할 때만 연관된 엔티티도 함께 조회(즉시 로딩)
			tx.commit();
		} catch (Exception e) {
			tx.rollback();
		} finally {
			em.close();
		}

		emf.close();
	}
}
