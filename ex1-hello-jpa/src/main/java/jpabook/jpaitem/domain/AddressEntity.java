package jpabook.jpaitem.domain;

import jakarta.persistence.Embedded;
import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.Id;

@Entity
public class AddressEntity {
    @Id @GeneratedValue
    private Long id;
    @Embedded
    private Address address;
}
