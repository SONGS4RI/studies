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
			Team team = new Team();
			team.setName("team1");
			em.persist(team);

			Member member = new Member();
			member.setAge(10);
			member.setUsername("member1");
			member.changeTeam(team);

			em.persist(member);

			String query = "select m from Member m where exists (select t from m.team t where t.name = 'team1')";
			List<Member> result = em.createQuery(query, Member.class)
					.getResultList();

			tx.commit();
		} catch (Exception e) {
			tx.rollback();
		} finally {
			em.close();
		}

		emf.close();
	}
}
